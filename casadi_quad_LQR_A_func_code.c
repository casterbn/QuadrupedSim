/* This file was automatically generated by CasADi.
   The CasADi copyright holders make no ownership claim of its contents. */
#ifdef __cplusplus
extern "C" {
#endif

/* How to prefix internal symbols */
#ifdef CASADI_CODEGEN_PREFIX
  #define CASADI_NAMESPACE_CONCAT(NS, ID) _CASADI_NAMESPACE_CONCAT(NS, ID)
  #define _CASADI_NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) CASADI_NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else
  #define CASADI_PREFIX(ID) casadi_quad_LQR_A_func_code_ ## ID
#endif

#include <math.h>
#include <string.h>
#ifdef MATLAB_MEX_FILE
#include <mex.h>
#endif

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int long long int
#endif

/* Add prefix to internal symbols */
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_fill CASADI_PREFIX(fill)
#define casadi_from_mex CASADI_PREFIX(from_mex)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_sq CASADI_PREFIX(sq)
#define casadi_to_mex CASADI_PREFIX(to_mex)

/* Symbol visibility in DLLs */
#ifndef CASADI_SYMBOL_EXPORT
  #if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    #if defined(STATIC_LINKED)
      #define CASADI_SYMBOL_EXPORT
    #else
      #define CASADI_SYMBOL_EXPORT __declspec(dllexport)
    #endif
  #elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
    #define CASADI_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define CASADI_SYMBOL_EXPORT
  #endif
#endif

casadi_real casadi_sq(casadi_real x) { return x*x;}

void casadi_fill(casadi_real* x, casadi_int n, casadi_real alpha) {
  casadi_int i;
  if (x) {
    for (i=0; i<n; ++i) *x++ = alpha;
  }
}

#ifdef MATLAB_MEX_FILE
casadi_real* casadi_from_mex(const mxArray* p, casadi_real* y, const casadi_int* sp, casadi_real* w) {
  casadi_int nrow, ncol, nnz, is_sparse, c, k;
  const casadi_int *colind, *row;
  size_t p_nrow, p_ncol;
  mwIndex *Jc, *Ir;
  const double* p_data;
  if (!mxIsDouble(p) || mxGetNumberOfDimensions(p)!=2)
    mexErrMsgIdAndTxt("Casadi:RuntimeError",
      "\"from_mex\" failed: Not a two-dimensional matrix of double precision.");
  nrow = *sp++;
  ncol = *sp++;
  nnz = sp[ncol];
  colind = sp;
  row = sp+ncol+1;
  p_nrow = mxGetM(p);
  p_ncol = mxGetN(p);
  is_sparse = mxIsSparse(p);
  if (is_sparse) {
#ifndef CASADI_MEX_NO_SPARSE
    Jc = mxGetJc(p);
    Ir = mxGetIr(p);
#else /* CASADI_MEX_NO_SPARSE */
    mexErrMsgIdAndTxt("Casadi:RuntimeError",
      "\"from_mex\" failed: Sparse inputs disabled.");
#endif /* CASADI_MEX_NO_SPARSE */
  }
  p_data = (const double*)mxGetData(p);
  if (p_nrow==1 && p_ncol==1) {
    double v = is_sparse && Jc[1]==0 ? 0 : *p_data;
    casadi_fill(y, nnz, v);
  } else {
    casadi_int tr = 0;
    if (nrow!=p_nrow || ncol!=p_ncol) {
      tr = nrow==p_ncol && ncol==p_nrow && (nrow==1 || ncol==1);
      if (!tr) mexErrMsgIdAndTxt("Casadi:RuntimeError",
                                 "\"from_mex\" failed: Dimension mismatch.");
    }
    if (is_sparse) {
      if (tr) {
        for (c=0; c<ncol; ++c)
          for (k=colind[c]; k<colind[c+1]; ++k) w[row[k]+c*nrow]=0;
        for (c=0; c<p_ncol; ++c)
          for (k=Jc[c]; k<Jc[c+1]; ++k) w[c+Ir[k]*p_ncol] = p_data[k];
        for (c=0; c<ncol; ++c)
          for (k=colind[c]; k<colind[c+1]; ++k) y[k] = w[row[k]+c*nrow];
      } else {
        for (c=0; c<ncol; ++c) {
          for (k=colind[c]; k<colind[c+1]; ++k) w[row[k]]=0;
          for (k=Jc[c]; k<Jc[c+1]; ++k) w[Ir[k]]=p_data[k];
          for (k=colind[c]; k<colind[c+1]; ++k) y[k]=w[row[k]];
        }
      }
    } else {
      for (c=0; c<ncol; ++c) {
        for (k=colind[c]; k<colind[c+1]; ++k) {
          y[k] = p_data[row[k]+c*nrow];
        }
      }
    }
  }
  return y;
}

#endif

#define casadi_to_double(x) ((double) x)

#ifdef MATLAB_MEX_FILE
mxArray* casadi_to_mex(const casadi_int* sp, const casadi_real* x) {
  casadi_int nrow, ncol, nnz, c, k;
  const casadi_int *colind, *row;
  mxArray *p;
  double *d;
#ifndef CASADI_MEX_NO_SPARSE
  casadi_int i;
  mwIndex *j;
#endif /* CASADI_MEX_NO_SPARSE */
  nrow = *sp++;
  ncol = *sp++;
  nnz = sp[ncol];
  colind = sp;
  row = sp+ncol+1;
#ifndef CASADI_MEX_NO_SPARSE
  if (nnz!=nrow*ncol) {
    p = mxCreateSparse(nrow, ncol, nnz, mxREAL);
    for (i=0, j=mxGetJc(p); i<=ncol; ++i) *j++ = *colind++;
    for (i=0, j=mxGetIr(p); i<nnz; ++i) *j++ = *row++;
    if (x) {
      d = (double*)mxGetData(p);
      for (i=0; i<nnz; ++i) *d++ = casadi_to_double(*x++);
    }
    return p;
  }
#endif /* CASADI_MEX_NO_SPARSE */
  p = mxCreateDoubleMatrix(nrow, ncol, mxREAL);
  if (x) {
    d = (double*)mxGetData(p);
    for (c=0; c<ncol; ++c) {
      for (k=colind[c]; k<colind[c+1]; ++k) {
        d[row[k]+c*nrow] = casadi_to_double(*x++);
      }
    }
  }
  return p;
}

#endif

static const casadi_int casadi_s0[28] = {24, 1, 0, 24, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
static const casadi_int casadi_s1[8] = {4, 1, 0, 4, 0, 1, 2, 3};
static const casadi_int casadi_s2[102] = {24, 24, 0, 3, 6, 9, 15, 20, 23, 24, 25, 26, 29, 34, 39, 42, 45, 48, 51, 54, 57, 60, 63, 66, 69, 72, 75, 9, 10, 11, 9, 10, 11, 9, 10, 11, 3, 4, 5, 9, 10, 11, 3, 5, 9, 10, 11, 9, 10, 11, 0, 1, 2, 3, 10, 11, 3, 4, 5, 9, 11, 3, 4, 5, 9, 10, 9, 10, 11, 9, 10, 11, 9, 10, 11, 9, 10, 11, 9, 10, 11, 9, 10, 11, 9, 10, 11, 9, 10, 11, 9, 10, 11, 9, 10, 11, 9, 10, 11, 9, 10, 11};

/* quad_LQR_A_func:(i0[24],i1[24],i2[4])->(o0[24x24,75nz]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a100, a101, a102, a103, a104, a105, a106, a107, a108, a109, a11, a110, a111, a112, a113, a114, a115, a116, a117, a118, a119, a12, a120, a121, a122, a123, a124, a125, a126, a127, a128, a129, a13, a130, a131, a132, a133, a134, a135, a136, a137, a138, a139, a14, a140, a141, a142, a143, a144, a145, a146, a147, a148, a149, a15, a150, a151, a152, a153, a154, a155, a16, a17, a18, a19, a2, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a3, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a4, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a5, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a6, a60, a61, a62, a63, a64, a65, a66, a67, a68, a69, a7, a70, a71, a72, a73, a74, a75, a76, a77, a78, a79, a8, a80, a81, a82, a83, a84, a85, a86, a87, a88, a89, a9, a90, a91, a92, a93, a94, a95, a96, a97, a98, a99;
  a0=arg[0]? arg[0][5] : 0;
  a1=cos(a0);
  a2=arg[0]? arg[0][4] : 0;
  a3=sin(a2);
  a4=(a1*a3);
  a5=arg[0]? arg[0][3] : 0;
  a6=sin(a5);
  a7=(a4*a6);
  a8=sin(a0);
  a9=cos(a5);
  a10=(a8*a9);
  a7=(a7-a10);
  a10=cos(a2);
  a11=cos(a5);
  a12=(a10*a11);
  a13=arg[2]? arg[2][3] : 0;
  a14=6.5843621399176966e+000;
  a15=arg[1]? arg[1][11] : 0;
  a16=(a14*a15);
  a16=(a13*a16);
  a17=(a12*a16);
  a18=sin(a0);
  a19=(a18*a3);
  a20=(a19*a11);
  a21=cos(a0);
  a22=sin(a5);
  a23=(a21*a22);
  a20=(a20-a23);
  a23=arg[1]? arg[1][10] : 0;
  a24=(a14*a23);
  a24=(a13*a24);
  a25=(a20*a24);
  a17=(a17+a25);
  a25=(a8*a22);
  a26=(a4*a11);
  a25=(a25+a26);
  a26=arg[1]? arg[1][9] : 0;
  a27=(a14*a26);
  a27=(a13*a27);
  a28=(a25*a27);
  a17=(a17+a28);
  a28=(a7*a17);
  a29=(a10*a6);
  a30=(a29*a16);
  a31=(a21*a9);
  a32=(a19*a6);
  a31=(a31+a32);
  a32=(a31*a24);
  a30=(a30+a32);
  a32=(a7*a27);
  a30=(a30+a32);
  a32=(a25*a30);
  a28=(a28-a32);
  a32=arg[2]? arg[2][2] : 0;
  a33=arg[1]? arg[1][8] : 0;
  a34=(a14*a33);
  a34=(a32*a34);
  a35=(a12*a34);
  a36=arg[1]? arg[1][7] : 0;
  a37=(a14*a36);
  a37=(a32*a37);
  a38=(a20*a37);
  a35=(a35+a38);
  a38=arg[1]? arg[1][6] : 0;
  a39=(a14*a38);
  a39=(a32*a39);
  a40=(a25*a39);
  a35=(a35+a40);
  a40=(a7*a35);
  a41=(a29*a34);
  a42=(a31*a37);
  a41=(a41+a42);
  a42=(a7*a39);
  a41=(a41+a42);
  a42=(a25*a41);
  a40=(a40-a42);
  a42=(a28+a40);
  a43=arg[2]? arg[2][1] : 0;
  a44=arg[1]? arg[1][5] : 0;
  a45=(a14*a44);
  a45=(a43*a45);
  a46=(a12*a45);
  a47=arg[1]? arg[1][4] : 0;
  a48=(a14*a47);
  a48=(a43*a48);
  a49=(a20*a48);
  a46=(a46+a49);
  a49=arg[1]? arg[1][3] : 0;
  a50=(a14*a49);
  a50=(a43*a50);
  a51=(a25*a50);
  a46=(a46+a51);
  a51=(a7*a46);
  a52=(a29*a45);
  a53=(a31*a48);
  a52=(a52+a53);
  a53=(a7*a50);
  a52=(a52+a53);
  a53=(a25*a52);
  a51=(a51-a53);
  a42=(a42+a51);
  a53=arg[2]? arg[2][0] : 0;
  a54=arg[1]? arg[1][2] : 0;
  a55=(a14*a54);
  a55=(a53*a55);
  a56=(a12*a55);
  a57=arg[1]? arg[1][1] : 0;
  a58=(a14*a57);
  a58=(a53*a58);
  a59=(a20*a58);
  a56=(a56+a59);
  a59=arg[1]? arg[1][0] : 0;
  a60=(a14*a59);
  a60=(a53*a60);
  a61=(a25*a60);
  a56=(a56+a61);
  a61=(a7*a56);
  a62=(a29*a55);
  a63=(a31*a58);
  a62=(a62+a63);
  a63=(a7*a60);
  a62=(a62+a63);
  a63=(a25*a62);
  a61=(a61-a63);
  a42=(a42+a61);
  a42=(-a42);
  if (res[0]!=0) res[0][0]=a42;
  a42=cos(a2);
  a63=(a1*a42);
  a64=-1.9365770999757932e+000;
  a65=(a64*a15);
  a65=(a13*a65);
  a66=(a12*a65);
  a67=1.9365770999757932e+000;
  a68=(a67*a23);
  a68=(a13*a68);
  a69=(a20*a68);
  a66=(a66-a69);
  a69=(a67*a26);
  a69=(a13*a69);
  a70=(a25*a69);
  a66=(a66-a70);
  a70=(a63*a66);
  a71=sin(a2);
  a72=(a71*a65);
  a73=(a18*a42);
  a74=(a73*a68);
  a72=(a72+a74);
  a74=(a63*a69);
  a72=(a72+a74);
  a74=(a25*a72);
  a70=(a70+a74);
  a74=(a64*a33);
  a74=(a32*a74);
  a75=(a12*a74);
  a76=(a67*a36);
  a76=(a32*a76);
  a77=(a20*a76);
  a75=(a75-a77);
  a77=(a67*a38);
  a77=(a32*a77);
  a78=(a25*a77);
  a75=(a75-a78);
  a78=(a63*a75);
  a79=(a71*a74);
  a80=(a73*a76);
  a79=(a79+a80);
  a80=(a63*a77);
  a79=(a79+a80);
  a80=(a25*a79);
  a78=(a78+a80);
  a80=(a70+a78);
  a81=(a64*a44);
  a81=(a43*a81);
  a82=(a12*a81);
  a83=(a67*a47);
  a83=(a43*a83);
  a84=(a20*a83);
  a82=(a82-a84);
  a84=(a67*a49);
  a84=(a43*a84);
  a85=(a25*a84);
  a82=(a82-a85);
  a85=(a63*a82);
  a86=(a71*a81);
  a87=(a73*a83);
  a86=(a86+a87);
  a87=(a63*a84);
  a86=(a86+a87);
  a87=(a25*a86);
  a85=(a85+a87);
  a80=(a80+a85);
  a87=(a64*a54);
  a87=(a53*a87);
  a88=(a12*a87);
  a89=(a67*a57);
  a89=(a53*a89);
  a90=(a20*a89);
  a88=(a88-a90);
  a90=(a67*a59);
  a90=(a53*a90);
  a91=(a25*a90);
  a88=(a88-a91);
  a91=(a63*a88);
  a92=(a71*a87);
  a93=(a73*a89);
  a92=(a92+a93);
  a93=(a63*a90);
  a92=(a92+a93);
  a93=(a25*a92);
  a91=(a91+a93);
  a80=(a80+a91);
  a80=(-a80);
  if (res[0]!=0) res[0][1]=a80;
  a80=1.6460905349794241e+000;
  a15=(a80*a15);
  a15=(a13*a15);
  a93=(a29*a15);
  a23=(a80*a23);
  a23=(a13*a23);
  a94=(a31*a23);
  a93=(a93+a94);
  a26=(a80*a26);
  a26=(a13*a26);
  a94=(a7*a26);
  a93=(a93+a94);
  a94=(a63*a93);
  a95=(a71*a15);
  a96=(a73*a23);
  a95=(a95-a96);
  a96=(a63*a26);
  a95=(a95-a96);
  a96=(a7*a95);
  a94=(a94+a96);
  a33=(a80*a33);
  a33=(a32*a33);
  a96=(a29*a33);
  a36=(a80*a36);
  a36=(a32*a36);
  a97=(a31*a36);
  a96=(a96+a97);
  a38=(a80*a38);
  a38=(a32*a38);
  a97=(a7*a38);
  a96=(a96+a97);
  a97=(a63*a96);
  a98=(a71*a33);
  a99=(a73*a36);
  a98=(a98-a99);
  a99=(a63*a38);
  a98=(a98-a99);
  a99=(a7*a98);
  a97=(a97+a99);
  a99=(a94+a97);
  a44=(a80*a44);
  a44=(a43*a44);
  a100=(a29*a44);
  a47=(a80*a47);
  a47=(a43*a47);
  a101=(a31*a47);
  a100=(a100+a101);
  a49=(a80*a49);
  a49=(a43*a49);
  a101=(a7*a49);
  a100=(a100+a101);
  a101=(a63*a100);
  a102=(a71*a44);
  a103=(a73*a47);
  a102=(a102-a103);
  a103=(a63*a49);
  a102=(a102-a103);
  a103=(a7*a102);
  a101=(a101+a103);
  a99=(a99+a101);
  a54=(a80*a54);
  a54=(a53*a54);
  a103=(a29*a54);
  a57=(a80*a57);
  a57=(a53*a57);
  a104=(a31*a57);
  a103=(a103+a104);
  a59=(a80*a59);
  a59=(a53*a59);
  a104=(a7*a59);
  a103=(a103+a104);
  a104=(a63*a103);
  a105=(a71*a54);
  a106=(a73*a57);
  a105=(a105-a106);
  a106=(a63*a59);
  a105=(a105-a106);
  a106=(a7*a105);
  a104=(a104+a106);
  a99=(a99+a104);
  a99=(-a99);
  if (res[0]!=0) res[0][2]=a99;
  a99=(a31*a17);
  a106=(a20*a30);
  a99=(a99-a106);
  a106=(a31*a35);
  a107=(a20*a41);
  a106=(a106-a107);
  a107=(a99+a106);
  a108=(a31*a46);
  a109=(a20*a52);
  a108=(a108-a109);
  a107=(a107+a108);
  a109=(a31*a56);
  a110=(a20*a62);
  a109=(a109-a110);
  a107=(a107+a109);
  a107=(-a107);
  if (res[0]!=0) res[0][3]=a107;
  a107=(a73*a66);
  a110=(a20*a72);
  a107=(a107+a110);
  a110=(a73*a75);
  a111=(a20*a79);
  a110=(a110+a111);
  a111=(a107+a110);
  a112=(a73*a82);
  a113=(a20*a86);
  a112=(a112+a113);
  a111=(a111+a112);
  a113=(a73*a88);
  a114=(a20*a92);
  a113=(a113+a114);
  a111=(a111+a113);
  a111=(-a111);
  if (res[0]!=0) res[0][4]=a111;
  a111=(a73*a93);
  a114=(a31*a95);
  a111=(a111+a114);
  a114=(a73*a96);
  a115=(a31*a98);
  a114=(a114+a115);
  a115=(a111+a114);
  a116=(a73*a100);
  a117=(a31*a102);
  a116=(a116+a117);
  a115=(a115+a116);
  a117=(a73*a103);
  a118=(a31*a105);
  a117=(a117+a118);
  a115=(a115+a117);
  a115=(-a115);
  if (res[0]!=0) res[0][5]=a115;
  a115=(a29*a17);
  a118=(a12*a30);
  a115=(a115-a118);
  a118=(a29*a35);
  a119=(a12*a41);
  a118=(a118-a119);
  a119=(a115+a118);
  a120=(a29*a46);
  a121=(a12*a52);
  a120=(a120-a121);
  a119=(a119+a120);
  a121=(a29*a56);
  a122=(a12*a62);
  a121=(a121-a122);
  a119=(a119+a121);
  a119=(-a119);
  if (res[0]!=0) res[0][6]=a119;
  a119=(a12*a72);
  a122=(a71*a66);
  a119=(a119-a122);
  a122=(a12*a79);
  a123=(a71*a75);
  a122=(a122-a123);
  a123=(a119+a122);
  a124=(a12*a86);
  a125=(a71*a82);
  a124=(a124-a125);
  a123=(a123+a124);
  a125=(a12*a92);
  a126=(a71*a88);
  a125=(a125-a126);
  a123=(a123+a125);
  a123=(-a123);
  if (res[0]!=0) res[0][7]=a123;
  a123=(a29*a95);
  a126=(a71*a93);
  a123=(a123-a126);
  a126=(a29*a98);
  a127=(a71*a96);
  a126=(a126-a127);
  a127=(a123+a126);
  a128=(a29*a102);
  a129=(a71*a100);
  a128=(a128-a129);
  a127=(a127+a128);
  a129=(a29*a105);
  a130=(a71*a103);
  a129=(a129-a130);
  a127=(a127+a129);
  a127=(-a127);
  if (res[0]!=0) res[0][8]=a127;
  a127=cos(a5);
  a130=tan(a2);
  a131=arg[0]? arg[0][10] : 0;
  a132=(a130*a131);
  a127=(a127*a132);
  a132=sin(a5);
  a133=tan(a2);
  a134=arg[0]? arg[0][11] : 0;
  a135=(a133*a134);
  a132=(a132*a135);
  a127=(a127-a132);
  if (res[0]!=0) res[0][9]=a127;
  a127=cos(a5);
  a127=(a127*a134);
  a132=sin(a5);
  a132=(a132*a131);
  a127=(a127+a132);
  a127=(-a127);
  if (res[0]!=0) res[0][10]=a127;
  a127=cos(a5);
  a132=cos(a2);
  a135=(a131/a132);
  a127=(a127*a135);
  a135=sin(a5);
  a136=cos(a2);
  a137=(a134/a136);
  a135=(a135*a137);
  a127=(a127-a135);
  if (res[0]!=0) res[0][11]=a127;
  a127=cos(a5);
  a135=arg[0]? arg[0][21] : 0;
  a137=arg[0]? arg[0][0] : 0;
  a135=(a135-a137);
  a138=(a7*a135);
  a139=arg[0]? arg[0][22] : 0;
  a140=arg[0]? arg[0][1] : 0;
  a139=(a139-a140);
  a141=(a31*a139);
  a138=(a138+a141);
  a141=arg[0]? arg[0][23] : 0;
  a142=arg[0]? arg[0][2] : 0;
  a141=(a141-a142);
  a143=(a29*a141);
  a138=(a138+a143);
  a143=(a138*a27);
  a144=(a135*a30);
  a143=(a143-a144);
  a144=arg[0]? arg[0][18] : 0;
  a144=(a144-a137);
  a145=(a144*a41);
  a143=(a143-a145);
  a145=(a7*a144);
  a146=arg[0]? arg[0][19] : 0;
  a146=(a146-a140);
  a147=(a31*a146);
  a145=(a145+a147);
  a147=arg[0]? arg[0][20] : 0;
  a147=(a147-a142);
  a148=(a29*a147);
  a145=(a145+a148);
  a148=(a145*a39);
  a143=(a143+a148);
  a148=arg[0]? arg[0][15] : 0;
  a148=(a148-a137);
  a149=(a148*a52);
  a143=(a143-a149);
  a149=(a7*a148);
  a150=arg[0]? arg[0][16] : 0;
  a150=(a150-a140);
  a151=(a31*a150);
  a149=(a149+a151);
  a151=arg[0]? arg[0][17] : 0;
  a151=(a151-a142);
  a152=(a29*a151);
  a149=(a149+a152);
  a152=(a149*a50);
  a143=(a143+a152);
  a152=arg[0]? arg[0][12] : 0;
  a152=(a152-a137);
  a137=(a152*a62);
  a143=(a143-a137);
  a7=(a7*a152);
  a137=arg[0]? arg[0][13] : 0;
  a137=(a137-a140);
  a31=(a31*a137);
  a7=(a7+a31);
  a31=arg[0]? arg[0][14] : 0;
  a31=(a31-a142);
  a29=(a29*a31);
  a7=(a7+a29);
  a29=(a7*a60);
  a143=(a143+a29);
  a29=(a8*a143);
  a142=(a138*a24);
  a140=(a139*a30);
  a142=(a142-a140);
  a140=(a145*a37);
  a142=(a142+a140);
  a140=(a146*a41);
  a142=(a142-a140);
  a140=(a149*a48);
  a142=(a142+a140);
  a140=(a150*a52);
  a142=(a142-a140);
  a140=(a7*a58);
  a142=(a142+a140);
  a140=(a137*a62);
  a142=(a142-a140);
  a140=(a21*a142);
  a29=(a29-a140);
  a29=(a127*a29);
  a140=sin(a5);
  a153=(a139*a17);
  a154=(a25*a135);
  a155=(a20*a139);
  a154=(a154+a155);
  a155=(a12*a141);
  a154=(a154+a155);
  a24=(a154*a24);
  a153=(a153-a24);
  a24=(a25*a144);
  a155=(a20*a146);
  a24=(a24+a155);
  a155=(a12*a147);
  a24=(a24+a155);
  a37=(a24*a37);
  a153=(a153-a37);
  a37=(a146*a35);
  a153=(a153+a37);
  a37=(a25*a148);
  a155=(a20*a150);
  a37=(a37+a155);
  a155=(a12*a151);
  a37=(a37+a155);
  a48=(a37*a48);
  a153=(a153-a48);
  a48=(a150*a46);
  a153=(a153+a48);
  a25=(a25*a152);
  a20=(a20*a137);
  a25=(a25+a20);
  a12=(a12*a31);
  a25=(a25+a12);
  a58=(a25*a58);
  a153=(a153-a58);
  a58=(a137*a56);
  a153=(a153+a58);
  a58=(a21*a153);
  a12=(a135*a17);
  a27=(a154*a27);
  a12=(a12-a27);
  a39=(a24*a39);
  a12=(a12-a39);
  a39=(a144*a35);
  a12=(a12+a39);
  a50=(a37*a50);
  a12=(a12-a50);
  a50=(a148*a46);
  a12=(a12+a50);
  a60=(a25*a60);
  a12=(a12-a60);
  a60=(a152*a56);
  a12=(a12+a60);
  a60=(a8*a12);
  a58=(a58-a60);
  a58=(a140*a58);
  a29=(a29-a58);
  a58=cos(a5);
  a17=(a141*a17);
  a60=(a154*a16);
  a17=(a17-a60);
  a60=(a24*a34);
  a17=(a17-a60);
  a35=(a147*a35);
  a17=(a17+a35);
  a35=(a37*a45);
  a17=(a17-a35);
  a46=(a151*a46);
  a17=(a17+a46);
  a46=(a25*a55);
  a17=(a17-a46);
  a56=(a31*a56);
  a17=(a17+a56);
  a56=(a10*a17);
  a46=(a19*a153);
  a56=(a56+a46);
  a46=(a4*a12);
  a56=(a56+a46);
  a56=(a58*a56);
  a29=(a29+a56);
  a56=sin(a5);
  a46=(a19*a142);
  a35=(a4*a143);
  a46=(a46+a35);
  a16=(a138*a16);
  a30=(a141*a30);
  a16=(a16-a30);
  a30=-1.8500000000000000e-001;
  a35=-4.2451727999999997e+000;
  a60=1.;
  a13=(a60-a13);
  a50=(a14*a13);
  a50=(a35*a50);
  a50=(a30*a50);
  a16=(a16+a50);
  a34=(a145*a34);
  a16=(a16+a34);
  a41=(a147*a41);
  a16=(a16-a41);
  a41=1.8500000000000000e-001;
  a32=(a60-a32);
  a34=(a14*a32);
  a34=(a35*a34);
  a34=(a41*a34);
  a16=(a16+a34);
  a45=(a149*a45);
  a16=(a16+a45);
  a52=(a151*a52);
  a16=(a16-a52);
  a43=(a60-a43);
  a52=(a14*a43);
  a52=(a35*a52);
  a52=(a30*a52);
  a16=(a16+a52);
  a55=(a7*a55);
  a16=(a16+a55);
  a62=(a31*a62);
  a16=(a16-a62);
  a53=(a60-a53);
  a62=(a14*a53);
  a62=(a35*a62);
  a62=(a41*a62);
  a16=(a16+a62);
  a62=(a10*a16);
  a46=(a46+a62);
  a46=(a56*a46);
  a29=(a29-a46);
  if (res[0]!=0) res[0][12]=a29;
  a29=(a135*a72);
  a46=(a63*a135);
  a62=(a73*a139);
  a46=(a46+a62);
  a62=(a71*a141);
  a46=(a46-a62);
  a62=(a46*a69);
  a55=(a63*a144);
  a52=(a73*a146);
  a55=(a55+a52);
  a52=(a71*a147);
  a55=(a55-a52);
  a52=(a55*a77);
  a62=(a62+a52);
  a52=(a63*a148);
  a45=(a73*a150);
  a52=(a52+a45);
  a45=(a71*a151);
  a52=(a52-a45);
  a45=(a52*a84);
  a62=(a62+a45);
  a63=(a63*a152);
  a73=(a73*a137);
  a63=(a63+a73);
  a71=(a71*a31);
  a63=(a63-a71);
  a71=(a63*a90);
  a62=(a62+a71);
  a29=(a29-a62);
  a62=(a144*a79);
  a29=(a29+a62);
  a62=(a148*a86);
  a29=(a29+a62);
  a62=(a152*a92);
  a29=(a29+a62);
  a62=(a8*a29);
  a71=(a139*a72);
  a73=(a46*a68);
  a45=(a55*a76);
  a73=(a73+a45);
  a45=(a52*a83);
  a73=(a73+a45);
  a45=(a63*a89);
  a73=(a73+a45);
  a71=(a71-a73);
  a73=(a146*a79);
  a71=(a71+a73);
  a73=(a150*a86);
  a71=(a71+a73);
  a73=(a137*a92);
  a71=(a71+a73);
  a73=(a21*a71);
  a62=(a62-a73);
  a127=(a127*a62);
  a62=(a19*a71);
  a73=(a4*a29);
  a62=(a62+a73);
  a73=(a46*a65);
  a45=2.6500000000000001e-001;
  a34=(a67*a13);
  a34=(a35*a34);
  a34=(a45*a34);
  a73=(a73+a34);
  a34=(a55*a74);
  a73=(a73+a34);
  a34=(a67*a32);
  a34=(a35*a34);
  a34=(a45*a34);
  a73=(a73+a34);
  a34=(a52*a81);
  a73=(a73+a34);
  a34=-2.6500000000000001e-001;
  a50=(a67*a43);
  a50=(a35*a50);
  a50=(a34*a50);
  a73=(a73+a50);
  a50=(a63*a87);
  a73=(a73+a50);
  a50=(a67*a53);
  a50=(a35*a50);
  a50=(a34*a50);
  a73=(a73+a50);
  a72=(a141*a72);
  a73=(a73+a72);
  a79=(a147*a79);
  a73=(a73+a79);
  a86=(a151*a86);
  a73=(a73+a86);
  a92=(a31*a92);
  a73=(a73+a92);
  a92=(a10*a73);
  a62=(a62+a92);
  a56=(a56*a62);
  a127=(a127-a56);
  if (res[0]!=0) res[0][13]=a127;
  a127=(a46*a15);
  a13=(a80*a13);
  a13=(a35*a13);
  a56=(a34*a13);
  a127=(a127+a56);
  a56=(a55*a33);
  a127=(a127+a56);
  a32=(a80*a32);
  a32=(a35*a32);
  a34=(a34*a32);
  a127=(a127+a34);
  a34=(a52*a44);
  a127=(a127+a34);
  a43=(a80*a43);
  a43=(a35*a43);
  a34=(a45*a43);
  a127=(a127+a34);
  a34=(a63*a54);
  a127=(a127+a34);
  a53=(a80*a53);
  a35=(a35*a53);
  a45=(a45*a35);
  a127=(a127+a45);
  a45=(a141*a95);
  a127=(a127+a45);
  a45=(a147*a98);
  a127=(a127+a45);
  a45=(a151*a102);
  a127=(a127+a45);
  a45=(a31*a105);
  a127=(a127+a45);
  a10=(a10*a127);
  a45=(a46*a23);
  a53=(a55*a36);
  a45=(a45+a53);
  a53=(a52*a47);
  a45=(a45+a53);
  a53=(a63*a57);
  a45=(a45+a53);
  a53=(a139*a95);
  a45=(a45+a53);
  a53=(a146*a98);
  a45=(a45+a53);
  a53=(a150*a102);
  a45=(a45+a53);
  a53=(a137*a105);
  a45=(a45+a53);
  a19=(a19*a45);
  a10=(a10+a19);
  a46=(a46*a26);
  a55=(a55*a38);
  a46=(a46+a55);
  a52=(a52*a49);
  a46=(a46+a52);
  a63=(a63*a59);
  a46=(a46+a63);
  a95=(a135*a95);
  a46=(a46+a95);
  a98=(a144*a98);
  a46=(a46+a98);
  a102=(a148*a102);
  a46=(a46+a102);
  a105=(a152*a105);
  a46=(a46+a105);
  a4=(a4*a46);
  a10=(a10+a4);
  a58=(a58*a10);
  a21=(a21*a45);
  a8=(a8*a46);
  a21=(a21-a8);
  a140=(a140*a21);
  a58=(a58-a140);
  if (res[0]!=0) res[0][14]=a58;
  a58=cos(a5);
  a140=(a58*a134);
  a21=cos(a2);
  a21=casadi_sq(a21);
  a140=(a140/a21);
  a21=sin(a5);
  a8=(a21*a131);
  a10=cos(a2);
  a10=casadi_sq(a10);
  a8=(a8/a10);
  a140=(a140+a8);
  if (res[0]!=0) res[0][15]=a140;
  a140=sin(a2);
  a8=cos(a5);
  a8=(a8/a136);
  a136=(a8/a136);
  a136=(a136*a134);
  a140=(a140*a136);
  a136=sin(a2);
  a10=sin(a5);
  a10=(a10/a132);
  a132=(a10/a132);
  a132=(a132*a131);
  a136=(a136*a132);
  a140=(a140+a136);
  if (res[0]!=0) res[0][16]=a140;
  a140=cos(a2);
  a136=(a11*a142);
  a132=(a6*a153);
  a136=(a136+a132);
  a132=(a18*a136);
  a4=(a11*a143);
  a105=(a6*a12);
  a4=(a4+a105);
  a105=(a1*a4);
  a132=(a132+a105);
  a132=(a140*a132);
  a105=sin(a2);
  a17=(a6*a17);
  a16=(a11*a16);
  a17=(a17+a16);
  a17=(a105*a17);
  a132=(a132-a17);
  if (res[0]!=0) res[0][17]=a132;
  a132=cos(a2);
  a65=(a154*a65);
  a17=(a141*a66);
  a65=(a65-a17);
  a74=(a24*a74);
  a65=(a65+a74);
  a74=(a147*a75);
  a65=(a65-a74);
  a81=(a37*a81);
  a65=(a65+a81);
  a81=(a151*a82);
  a65=(a65-a81);
  a87=(a25*a87);
  a65=(a65+a87);
  a87=(a31*a88);
  a65=(a65-a87);
  a65=(a132*a65);
  a2=sin(a2);
  a68=(a154*a68);
  a87=(a139*a66);
  a68=(a68+a87);
  a76=(a24*a76);
  a68=(a68+a76);
  a76=(a146*a75);
  a68=(a68+a76);
  a83=(a37*a83);
  a68=(a68+a83);
  a83=(a150*a82);
  a68=(a68+a83);
  a89=(a25*a89);
  a68=(a68+a89);
  a89=(a137*a88);
  a68=(a68+a89);
  a89=(a18*a68);
  a66=(a135*a66);
  a154=(a154*a69);
  a66=(a66+a154);
  a75=(a144*a75);
  a66=(a66+a75);
  a24=(a24*a77);
  a66=(a66+a24);
  a82=(a148*a82);
  a66=(a66+a82);
  a37=(a37*a84);
  a66=(a66+a37);
  a88=(a152*a88);
  a66=(a66+a88);
  a25=(a25*a90);
  a66=(a66+a25);
  a25=(a1*a66);
  a89=(a89+a25);
  a89=(a2*a89);
  a65=(a65-a89);
  a89=(a11*a71);
  a25=(a18*a89);
  a90=(a11*a29);
  a88=(a1*a90);
  a25=(a25+a88);
  a25=(a140*a25);
  a65=(a65+a25);
  a11=(a11*a73);
  a11=(a105*a11);
  a65=(a65-a11);
  if (res[0]!=0) res[0][18]=a65;
  a15=(a138*a15);
  a13=(a41*a13);
  a15=(a15-a13);
  a33=(a145*a33);
  a15=(a15+a33);
  a32=(a30*a32);
  a15=(a15-a32);
  a44=(a149*a44);
  a15=(a15+a44);
  a41=(a41*a43);
  a15=(a15-a41);
  a54=(a7*a54);
  a15=(a15+a54);
  a30=(a30*a35);
  a15=(a15-a30);
  a141=(a141*a93);
  a15=(a15-a141);
  a147=(a147*a96);
  a15=(a15-a147);
  a151=(a151*a100);
  a15=(a15-a151);
  a31=(a31*a103);
  a15=(a15-a31);
  a132=(a132*a15);
  a139=(a139*a93);
  a23=(a138*a23);
  a36=(a145*a36);
  a23=(a23+a36);
  a47=(a149*a47);
  a23=(a23+a47);
  a57=(a7*a57);
  a23=(a23+a57);
  a139=(a139-a23);
  a146=(a146*a96);
  a139=(a139+a146);
  a150=(a150*a100);
  a139=(a139+a150);
  a137=(a137*a103);
  a139=(a139+a137);
  a137=(a18*a139);
  a135=(a135*a93);
  a138=(a138*a26);
  a145=(a145*a38);
  a138=(a138+a145);
  a149=(a149*a49);
  a138=(a138+a149);
  a7=(a7*a59);
  a138=(a138+a7);
  a135=(a135-a138);
  a144=(a144*a96);
  a135=(a135+a144);
  a148=(a148*a100);
  a135=(a135+a148);
  a152=(a152*a103);
  a135=(a135+a152);
  a152=(a1*a135);
  a137=(a137+a152);
  a2=(a2*a137);
  a132=(a132-a2);
  a2=(a6*a45);
  a18=(a18*a2);
  a137=(a6*a46);
  a1=(a1*a137);
  a18=(a18+a1);
  a140=(a140*a18);
  a132=(a132+a140);
  a6=(a6*a127);
  a105=(a105*a6);
  a132=(a132-a105);
  if (res[0]!=0) res[0][19]=a132;
  a132=cos(a0);
  a136=(a3*a136);
  a136=(a132*a136);
  a105=sin(a0);
  a153=(a9*a153);
  a142=(a22*a142);
  a153=(a153-a142);
  a153=(a105*a153);
  a136=(a136-a153);
  a153=cos(a0);
  a143=(a22*a143);
  a12=(a9*a12);
  a143=(a143-a12);
  a143=(a153*a143);
  a136=(a136+a143);
  a0=sin(a0);
  a4=(a3*a4);
  a4=(a0*a4);
  a136=(a136-a4);
  if (res[0]!=0) res[0][20]=a136;
  a68=(a42*a68);
  a89=(a3*a89);
  a68=(a68+a89);
  a68=(a132*a68);
  a71=(a22*a71);
  a71=(a105*a71);
  a68=(a68+a71);
  a22=(a22*a29);
  a22=(a153*a22);
  a68=(a68+a22);
  a66=(a42*a66);
  a90=(a3*a90);
  a66=(a66+a90);
  a66=(a0*a66);
  a68=(a68-a66);
  if (res[0]!=0) res[0][21]=a68;
  a139=(a42*a139);
  a2=(a3*a2);
  a139=(a139+a2);
  a132=(a132*a139);
  a45=(a9*a45);
  a105=(a105*a45);
  a132=(a132-a105);
  a9=(a9*a46);
  a153=(a153*a9);
  a132=(a132-a153);
  a42=(a42*a135);
  a3=(a3*a137);
  a42=(a42+a3);
  a0=(a0*a42);
  a132=(a132-a0);
  if (res[0]!=0) res[0][22]=a132;
  if (res[0]!=0) res[0][23]=a60;
  if (res[0]!=0) res[0][24]=a60;
  if (res[0]!=0) res[0][25]=a60;
  if (res[0]!=0) res[0][26]=a60;
  a60=1.5187499999999998e-001;
  a132=(a60*a134);
  a132=(a64*a132);
  a0=6.0749999999999993e-001;
  a42=(a67*a134);
  a42=(a0*a42);
  a132=(a132+a42);
  if (res[0]!=0) res[0][27]=a132;
  a132=5.1637499999999992e-001;
  a42=-1.6460905349794241e+000;
  a3=(a42*a131);
  a3=(a132*a3);
  a137=(a60*a131);
  a137=(a80*a137);
  a3=(a3+a137);
  if (res[0]!=0) res[0][28]=a3;
  a21=(a21*a130);
  if (res[0]!=0) res[0][29]=a21;
  a21=cos(a5);
  if (res[0]!=0) res[0][30]=a21;
  if (res[0]!=0) res[0][31]=a10;
  a10=-6.5843621399176966e+000;
  a21=(a10*a134);
  a21=(a0*a21);
  a134=(a132*a134);
  a134=(a14*a134);
  a21=(a21+a134);
  if (res[0]!=0) res[0][32]=a21;
  a21=arg[0]? arg[0][9] : 0;
  a134=(a132*a21);
  a42=(a42*a134);
  a80=(a80*a21);
  a80=(a60*a80);
  a42=(a42+a80);
  if (res[0]!=0) res[0][33]=a42;
  a58=(a58*a133);
  if (res[0]!=0) res[0][34]=a58;
  a5=sin(a5);
  a5=(-a5);
  if (res[0]!=0) res[0][35]=a5;
  if (res[0]!=0) res[0][36]=a8;
  a8=(a0*a131);
  a10=(a10*a8);
  a14=(a14*a131);
  a132=(a132*a14);
  a10=(a10+a132);
  if (res[0]!=0) res[0][37]=a10;
  a64=(a64*a21);
  a60=(a60*a64);
  a0=(a0*a21);
  a67=(a67*a0);
  a60=(a60+a67);
  if (res[0]!=0) res[0][38]=a60;
  if (res[0]!=0) res[0][39]=a61;
  if (res[0]!=0) res[0][40]=a91;
  if (res[0]!=0) res[0][41]=a104;
  if (res[0]!=0) res[0][42]=a109;
  if (res[0]!=0) res[0][43]=a113;
  if (res[0]!=0) res[0][44]=a117;
  if (res[0]!=0) res[0][45]=a121;
  if (res[0]!=0) res[0][46]=a125;
  if (res[0]!=0) res[0][47]=a129;
  if (res[0]!=0) res[0][48]=a51;
  if (res[0]!=0) res[0][49]=a85;
  if (res[0]!=0) res[0][50]=a101;
  if (res[0]!=0) res[0][51]=a108;
  if (res[0]!=0) res[0][52]=a112;
  if (res[0]!=0) res[0][53]=a116;
  if (res[0]!=0) res[0][54]=a120;
  if (res[0]!=0) res[0][55]=a124;
  if (res[0]!=0) res[0][56]=a128;
  if (res[0]!=0) res[0][57]=a40;
  if (res[0]!=0) res[0][58]=a78;
  if (res[0]!=0) res[0][59]=a97;
  if (res[0]!=0) res[0][60]=a106;
  if (res[0]!=0) res[0][61]=a110;
  if (res[0]!=0) res[0][62]=a114;
  if (res[0]!=0) res[0][63]=a118;
  if (res[0]!=0) res[0][64]=a122;
  if (res[0]!=0) res[0][65]=a126;
  if (res[0]!=0) res[0][66]=a28;
  if (res[0]!=0) res[0][67]=a70;
  if (res[0]!=0) res[0][68]=a94;
  if (res[0]!=0) res[0][69]=a99;
  if (res[0]!=0) res[0][70]=a107;
  if (res[0]!=0) res[0][71]=a111;
  if (res[0]!=0) res[0][72]=a115;
  if (res[0]!=0) res[0][73]=a119;
  if (res[0]!=0) res[0][74]=a123;
  return 0;
}

CASADI_SYMBOL_EXPORT int quad_LQR_A_func(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int quad_LQR_A_func_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int quad_LQR_A_func_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void quad_LQR_A_func_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int quad_LQR_A_func_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void quad_LQR_A_func_release(int mem) {
}

CASADI_SYMBOL_EXPORT void quad_LQR_A_func_incref(void) {
}

CASADI_SYMBOL_EXPORT void quad_LQR_A_func_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int quad_LQR_A_func_n_in(void) { return 3;}

CASADI_SYMBOL_EXPORT casadi_int quad_LQR_A_func_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real quad_LQR_A_func_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* quad_LQR_A_func_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* quad_LQR_A_func_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* quad_LQR_A_func_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s0;
    case 2: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* quad_LQR_A_func_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s2;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int quad_LQR_A_func_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 3;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

#ifdef MATLAB_MEX_FILE
void mex_quad_LQR_A_func(int resc, mxArray *resv[], int argc, const mxArray *argv[]) {
  casadi_int i, j;
  casadi_real w[283];
  casadi_int *iw = 0;
  const casadi_real* arg[3] = {0};
  casadi_real* res[1] = {0};
  if (argc>3) mexErrMsgIdAndTxt("Casadi:RuntimeError","Evaluation of \"quad_LQR_A_func\" failed. Too many input arguments (%d, max 3)", argc);
  if (resc>1) mexErrMsgIdAndTxt("Casadi:RuntimeError","Evaluation of \"quad_LQR_A_func\" failed. Too many output arguments (%d, max 1)", resc);
  if (--argc>=0) arg[0] = casadi_from_mex(argv[0], w, casadi_s0, w+127);
  if (--argc>=0) arg[1] = casadi_from_mex(argv[1], w+24, casadi_s0, w+127);
  if (--argc>=0) arg[2] = casadi_from_mex(argv[2], w+48, casadi_s1, w+127);
  --resc;
  res[0] = w+52;
  i = quad_LQR_A_func(arg, res, iw, w+127, 0);
  if (i) mexErrMsgIdAndTxt("Casadi:RuntimeError","Evaluation of \"quad_LQR_A_func\" failed.");
  if (res[0]) resv[0] = casadi_to_mex(casadi_s2, res[0]);
}
#endif


#ifdef MATLAB_MEX_FILE
void mexFunction(int resc, mxArray *resv[], int argc, const mxArray *argv[]) {
  char buf[16];
  int buf_ok = --argc >= 0 && !mxGetString(*argv++, buf, sizeof(buf));
  if (!buf_ok) {
    /* name error */
  } else if (strcmp(buf, "quad_LQR_A_func")==0) {
    mex_quad_LQR_A_func(resc, resv, argc, argv);
    return;
  }
  mexErrMsgTxt("First input should be a command string. Possible values: 'quad_LQR_A_func'");
}
#endif
#ifdef __cplusplus
} /* extern "C" */
#endif
