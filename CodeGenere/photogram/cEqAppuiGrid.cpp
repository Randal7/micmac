/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr

   
    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.

[1] M. Pierrot-Deseilligny, N. Paparoditis.
    "A multiresolution and optimization-based image matching approach:
    An application to surface reconstruction from SPOT5-HRS stereo imagery."
    In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
    (With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
    d'images, adapte au contexte geograhique" to appears in 
    Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

   MicMac est un logiciel de mise en correspondance d'image adapte 
   au contexte de recherche en information geographique. Il s'appuie sur
   la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
   licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

    MicMac is an open source software specialized in image matching
    for research in geographic information. MicMac is built on the
    eLiSe image library. MicMac is governed by the  "Cecill-B licence".
    See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/
// File Automatically generated by eLiSe

#include "general/all.h"
#include "private/all.h"
#include "cEqAppuiGrid.h"


cEqAppuiGrid::cEqAppuiGrid():
    cElCompiledFonc(2)
{
   AddIntRef (cIncIntervale("Orient",6,12));
   AddIntRef (cIncIntervale("SomA1",4,6));
   AddIntRef (cIncIntervale("SomA2",0,2));
   AddIntRef (cIncIntervale("SomA3",2,4));
   Close(false);
}



void cEqAppuiGrid::ComputeVal()
{
// cout << "ComputeVal \n";
   double tmp0_ = mCompCoord[6];
   double tmp1_ = mCompCoord[7];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = sin(tmp0_);
   double tmp4_ = cos(tmp0_);
   double tmp5_ = sin(tmp1_);
   double tmp6_ = mCompCoord[8];
   double tmp7_ = mCompCoord[9];
   double tmp8_ = mLocXTer-tmp7_;
// cout << "X: " <<  mLocXTer << " " << tmp7_ << "\n";
   double tmp9_ = sin(tmp6_);
   double tmp10_ = -(tmp9_);
   double tmp11_ = -(tmp5_);
   double tmp12_ = cos(tmp6_);
   double tmp13_ = mCompCoord[10];
   double tmp14_ = mLocYTer-tmp13_;
// cout << "Y: " <<  mLocYTer << " " << tmp13_ << "\n";
   double tmp15_ = mCompCoord[11];
   double tmp16_ = mLocZTer-tmp15_;
// cout << "Z: " <<  mLocZTer << " " << tmp15_ << "\n";
   double tmp17_ = -(tmp3_);
   double tmp18_ = tmp4_*tmp11_;
   double tmp19_ = tmp3_*tmp11_;
   double tmp20_ = tmp17_*tmp10_;
   double tmp21_ = tmp18_*tmp12_;
   double tmp22_ = tmp20_+tmp21_;
   double tmp23_ = (tmp22_)*(tmp8_);
   double tmp24_ = tmp4_*tmp10_;
   double tmp25_ = tmp19_*tmp12_;
   double tmp26_ = tmp24_+tmp25_;
   double tmp27_ = (tmp26_)*(tmp14_);
   double tmp28_ = tmp23_+tmp27_;
   double tmp29_ = tmp2_*tmp12_;
   double tmp30_ = tmp29_*(tmp16_);
   double tmp31_ = tmp28_+tmp30_;

  mVal[0] = (mCompCoord[4]*mLocPds1+mCompCoord[0]*mLocPds2+mCompCoord[2]*mLocPds3)-(tmp4_*tmp2_*(tmp8_)+tmp3_*tmp2_*(tmp14_)+tmp5_*(tmp16_))/(tmp31_);

  mVal[1] = (mCompCoord[5]*mLocPds1+mCompCoord[1]*mLocPds2+mCompCoord[3]*mLocPds3)-((tmp17_*tmp12_+tmp18_*tmp9_)*(tmp8_)+(tmp4_*tmp12_+tmp19_*tmp9_)*(tmp14_)+tmp2_*tmp9_*(tmp16_))/(tmp31_);

}


void cEqAppuiGrid::ComputeValDeriv()
{
// cout << "ComputeValDeriv \n";
   double tmp0_ = mCompCoord[6];
   double tmp1_ = mCompCoord[7];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = sin(tmp0_);
   double tmp4_ = cos(tmp0_);
   double tmp5_ = sin(tmp1_);
   double tmp6_ = mCompCoord[8];
   double tmp7_ = mCompCoord[9];
   double tmp8_ = mLocXTer-tmp7_;
   double tmp9_ = sin(tmp6_);
   double tmp10_ = -(tmp9_);
   double tmp11_ = -(tmp5_);
   double tmp12_ = cos(tmp6_);
   double tmp13_ = mCompCoord[10];
   double tmp14_ = mLocYTer-tmp13_;
   double tmp15_ = mCompCoord[11];
   double tmp16_ = mLocZTer-tmp15_;
   double tmp17_ = tmp4_*tmp2_;
   double tmp18_ = -(tmp3_);
   double tmp19_ = tmp18_*tmp10_;
   double tmp20_ = tmp4_*tmp11_;
   double tmp21_ = tmp20_*tmp12_;
   double tmp22_ = tmp19_+tmp21_;
   double tmp23_ = (tmp22_)*(tmp8_);
   double tmp24_ = tmp4_*tmp10_;
   double tmp25_ = tmp3_*tmp11_;
   double tmp26_ = tmp25_*tmp12_;
   double tmp27_ = tmp24_+tmp26_;
   double tmp28_ = (tmp27_)*(tmp14_);
   double tmp29_ = tmp23_+tmp28_;
   double tmp30_ = tmp2_*tmp12_;
   double tmp31_ = tmp30_*(tmp16_);
   double tmp32_ = tmp29_+tmp31_;
   double tmp33_ = tmp17_*(tmp8_);
   double tmp34_ = tmp3_*tmp2_;
   double tmp35_ = tmp34_*(tmp14_);
   double tmp36_ = tmp33_+tmp35_;
   double tmp37_ = tmp5_*(tmp16_);
   double tmp38_ = tmp36_+tmp37_;
   double tmp39_ = -(1);
   double tmp40_ = tmp39_*tmp3_;
   double tmp41_ = tmp39_*tmp5_;
   double tmp42_ = -(tmp2_);
   double tmp43_ = ElSquare(tmp32_);
   double tmp44_ = -(tmp12_);
   double tmp45_ = tmp39_*tmp9_;
   double tmp46_ = -(tmp4_);
   double tmp47_ = tmp40_*tmp11_;
   double tmp48_ = tmp20_*tmp9_;
   double tmp49_ = tmp18_*tmp12_;
   double tmp50_ = tmp49_+tmp48_;
   double tmp51_ = (tmp50_)*(tmp8_);
   double tmp52_ = tmp4_*tmp12_;
   double tmp53_ = tmp25_*tmp9_;
   double tmp54_ = tmp52_+tmp53_;
   double tmp55_ = (tmp54_)*(tmp14_);
   double tmp56_ = tmp51_+tmp55_;
   double tmp57_ = tmp2_*tmp9_;
   double tmp58_ = tmp57_*(tmp16_);
   double tmp59_ = tmp56_+tmp58_;
   double tmp60_ = tmp46_*tmp10_;
   double tmp61_ = tmp47_*tmp12_;
   double tmp62_ = tmp60_+tmp61_;
   double tmp63_ = (tmp62_)*(tmp8_);
   double tmp64_ = tmp40_*tmp10_;
   double tmp65_ = tmp64_+tmp21_;
   double tmp66_ = (tmp65_)*(tmp14_);
   double tmp67_ = tmp63_+tmp66_;
   double tmp68_ = tmp42_*tmp4_;
   double tmp69_ = tmp42_*tmp3_;
   double tmp70_ = tmp68_*tmp12_;
   double tmp71_ = tmp70_*(tmp8_);
   double tmp72_ = tmp69_*tmp12_;
   double tmp73_ = tmp72_*(tmp14_);
   double tmp74_ = tmp71_+tmp73_;
   double tmp75_ = tmp41_*tmp12_;
   double tmp76_ = tmp75_*(tmp16_);
   double tmp77_ = tmp74_+tmp76_;
   double tmp78_ = tmp44_*tmp18_;
   double tmp79_ = tmp45_*tmp20_;
   double tmp80_ = tmp78_+tmp79_;
   double tmp81_ = (tmp80_)*(tmp8_);
   double tmp82_ = tmp44_*tmp4_;
   double tmp83_ = tmp45_*tmp25_;
   double tmp84_ = tmp82_+tmp83_;
   double tmp85_ = (tmp84_)*(tmp14_);
   double tmp86_ = tmp81_+tmp85_;
   double tmp87_ = tmp45_*tmp2_;
   double tmp88_ = tmp87_*(tmp16_);
   double tmp89_ = tmp86_+tmp88_;
   double tmp90_ = tmp39_*(tmp22_);
   double tmp91_ = tmp39_*(tmp27_);
   double tmp92_ = tmp39_*tmp30_;

  mVal[0] = (mCompCoord[4]*mLocPds1+mCompCoord[0]*mLocPds2+mCompCoord[2]*mLocPds3)-(tmp38_)/(tmp32_);

  mCompDer[0][0] = mLocPds2;
  mCompDer[0][1] = 0;
  mCompDer[0][2] = mLocPds3;
  mCompDer[0][3] = 0;
  mCompDer[0][4] = mLocPds1;
  mCompDer[0][5] = 0;
  mCompDer[0][6] = -(((tmp40_*tmp2_*(tmp8_)+tmp17_*(tmp14_))*(tmp32_)-(tmp38_)*(tmp67_))/tmp43_);
  mCompDer[0][7] = -(((tmp41_*tmp4_*(tmp8_)+tmp41_*tmp3_*(tmp14_)+tmp2_*(tmp16_))*(tmp32_)-(tmp38_)*(tmp77_))/tmp43_);
  mCompDer[0][8] = -(-((tmp38_)*(tmp89_))/tmp43_);
  mCompDer[0][9] = -((tmp39_*tmp17_*(tmp32_)-(tmp38_)*tmp90_)/tmp43_);
  mCompDer[0][10] = -((tmp39_*tmp34_*(tmp32_)-(tmp38_)*tmp91_)/tmp43_);
  mCompDer[0][11] = -((tmp41_*(tmp32_)-(tmp38_)*tmp92_)/tmp43_);
  mVal[1] = (mCompCoord[5]*mLocPds1+mCompCoord[1]*mLocPds2+mCompCoord[3]*mLocPds3)-(tmp59_)/(tmp32_);

  mCompDer[1][0] = 0;
  mCompDer[1][1] = mLocPds2;
  mCompDer[1][2] = 0;
  mCompDer[1][3] = mLocPds3;
  mCompDer[1][4] = 0;
  mCompDer[1][5] = mLocPds1;
  mCompDer[1][6] = -((((tmp46_*tmp12_+tmp47_*tmp9_)*(tmp8_)+(tmp40_*tmp12_+tmp48_)*(tmp14_))*(tmp32_)-(tmp59_)*(tmp67_))/tmp43_);
  mCompDer[1][7] = -(((tmp68_*tmp9_*(tmp8_)+tmp69_*tmp9_*(tmp14_)+tmp41_*tmp9_*(tmp16_))*(tmp32_)-(tmp59_)*(tmp77_))/tmp43_);
  mCompDer[1][8] = -((((tmp45_*tmp18_+tmp12_*tmp20_)*(tmp8_)+(tmp45_*tmp4_+tmp12_*tmp25_)*(tmp14_)+tmp12_*tmp2_*(tmp16_))*(tmp32_)-(tmp59_)*(tmp89_))/tmp43_);
  mCompDer[1][9] = -((tmp39_*(tmp50_)*(tmp32_)-(tmp59_)*tmp90_)/tmp43_);
  mCompDer[1][10] = -((tmp39_*(tmp54_)*(tmp32_)-(tmp59_)*tmp91_)/tmp43_);
  mCompDer[1][11] = -((tmp39_*tmp57_*(tmp32_)-(tmp59_)*tmp92_)/tmp43_);
}


void cEqAppuiGrid::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cEqAppuiGrid Has no Der Sec");
}

void cEqAppuiGrid::SetPds1(double aVal){ mLocPds1 = aVal;}
void cEqAppuiGrid::SetPds2(double aVal){ mLocPds2 = aVal;}
void cEqAppuiGrid::SetPds3(double aVal){ mLocPds3 = aVal;}
void cEqAppuiGrid::SetXTer(double aVal){ mLocXTer = aVal;}
void cEqAppuiGrid::SetYTer(double aVal){ mLocYTer = aVal;}
void cEqAppuiGrid::SetZTer(double aVal){ mLocZTer = aVal;}



double * cEqAppuiGrid::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "Pds1") return & mLocPds1;
   if (aName == "Pds2") return & mLocPds2;
   if (aName == "Pds3") return & mLocPds3;
   if (aName == "XTer") return & mLocXTer;
   if (aName == "YTer") return & mLocYTer;
   if (aName == "ZTer") return & mLocZTer;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cEqAppuiGrid::mTheAuto("cEqAppuiGrid",cEqAppuiGrid::Alloc);


cElCompiledFonc *  cEqAppuiGrid::Alloc()
{  return new cEqAppuiGrid();
}



/*Footer-MicMac-eLiSe-25/06/2007

Ce logiciel est un programme informatique servant à la mise en
correspondances d'images pour la reconstruction du relief.

Ce logiciel est régi par la licence CeCILL-B soumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL-B telle que diffusée par le CEA, le CNRS et l'INRIA 
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant 
donné sa spécificité de logiciel libre, qui peut le rendre complexe à 
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement, 
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité. 

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez 
pris connaissance de la licence CeCILL-B, et que vous en avez accepté les
termes.
Footer-MicMac-eLiSe-25/06/2007*/
