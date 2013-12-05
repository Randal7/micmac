// File Automatically generated by eLiSe
#include "StdAfx.h"


class cEqAppui_PProjInc_M2CFour7x2: public cElCompiledFonc
{
   public :

      cEqAppui_PProjInc_M2CFour7x2();
      void ComputeVal();
      void ComputeValDeriv();
      void ComputeValDerivHessian();
      double * AdrVarLocFromString(const std::string &);
      void SetFour7x2_State_0_0(double);
      void SetFour7x2_State_1_0(double);
      void SetFour7x2_State_2_0(double);
      void SetProjI_x(double);
      void SetProjI_y(double);
      void SetProjI_z(double);
      void SetProjJ_x(double);
      void SetProjJ_y(double);
      void SetProjJ_z(double);
      void SetProjK_x(double);
      void SetProjK_y(double);
      void SetProjK_z(double);
      void SetProjP0_x(double);
      void SetProjP0_y(double);
      void SetProjP0_z(double);
      void SetScNorm(double);
      void SetXIm(double);
      void SetYIm(double);


      static cAutoAddEntry  mTheAuto;
      static cElCompiledFonc *  Alloc();
   private :

      double mLocFour7x2_State_0_0;
      double mLocFour7x2_State_1_0;
      double mLocFour7x2_State_2_0;
      double mLocProjI_x;
      double mLocProjI_y;
      double mLocProjI_z;
      double mLocProjJ_x;
      double mLocProjJ_y;
      double mLocProjJ_z;
      double mLocProjK_x;
      double mLocProjK_y;
      double mLocProjK_z;
      double mLocProjP0_x;
      double mLocProjP0_y;
      double mLocProjP0_z;
      double mLocScNorm;
      double mLocXIm;
      double mLocYIm;
};
