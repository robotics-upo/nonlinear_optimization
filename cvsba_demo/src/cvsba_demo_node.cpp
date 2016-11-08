#include <cvsba/cvsba.h>
 
int main(int argc, char **argv) {
  
  /****** INPUT DATA *****************/
     std::vector< cv::Point3d > points3D;
     std::vector< std::vector< cv::Point2d > > pointsImg;
     std::vector< std::vector< int > > visibility;
     std::vector< cv::Mat > cameraMatrix, distCoeffs, R, T;
          
     int NPOINTS=32; 	// number of 3d points
     int NCAMS=2; 	// number of cameras
  
     // fill 3D points
     points3D.resize(NPOINTS);
     points3D[0] =cv::Point3d(-0.9991,-0.6847,-0.9559);
     points3D[1] =cv::Point3d(-0.009,0.4921,0.9615);
     points3D[2] =cv::Point3d(-0.7931,0.5179,-0.366);
     points3D[3] =cv::Point3d(0.4145,-0.6645,-0.3143);
     points3D[4] =cv::Point3d(-0.4209,0.889,0.94);
     points3D[5] =cv::Point3d(-0.5508,0.5276,-0.0215);
     points3D[6] =cv::Point3d(0.315,-0.0378,-0.2357);
     points3D[7] =cv::Point3d(0.4756,0.2084,0.1111);
     points3D[8] =cv::Point3d(0.2014,-0.8323,-0.0673);
     points3D[9] =cv::Point3d(-0.88,0.273,0.9805);
     points3D[10] =cv::Point3d(0.1545,0.6321,-0.3621);
     points3D[11] =cv::Point3d(0.2086,-0.3669,-0.8648);
     points3D[12] =cv::Point3d(0.5074,0.1772,-1.0049);
     points3D[13] =cv::Point3d(-0.8486,-0.4221,-0.3122);
     points3D[14] =cv::Point3d(0.2002,0.5342,-0.065);
     points3D[15] =cv::Point3d(0.1454,0.9734,-0.5273);
     points3D[16] =cv::Point3d(-0.5389,0.2936,0.4411);
     points3D[17] =cv::Point3d(0.2355,0.1312,-0.0085);
     points3D[18] =cv::Point3d(-0.3104,-0.6621,0.1702);
     points3D[19] =cv::Point3d(0.9595,-0.5569,-0.5516);
     points3D[20] =cv::Point3d(-0.7179,0.9548,-0.9295);
     points3D[21] =cv::Point3d(-0.0538,0.5055,0.0608);
     points3D[22] =cv::Point3d(0.4234,0.0381,-0.7558);
     points3D[23] =cv::Point3d(0.4295,0.5325,0.1793);
     points3D[24] =cv::Point3d(-0.5207,0.0899,-0.2965);
     points3D[25] =cv::Point3d(0.4043,-0.7746,0.0342);
     points3D[26] =cv::Point3d(-0.7648,0.0447,-0.315);
     points3D[27] =cv::Point3d(0.6664,-0.7298,0.8063);
     points3D[28] =cv::Point3d(-0.3321,-0.0349,-0.8696);
     points3D[29] =cv::Point3d(-0.8046,-0.0644,-0.4165);
     points3D[30] =cv::Point3d(-0.3652,0.2429,-0.1035);
     points3D[31] =cv::Point3d(0.0826,-0.4689,-0.5928);
     
     // fill image projections
     pointsImg.resize(NCAMS);
     for(int i=0; i<NCAMS; i++) pointsImg[i].resize(NPOINTS);    
     pointsImg[0][0] =cv::Point2d(112.468,68.9535);
     pointsImg[1][0] =cv::Point2d(1087.52,731.054);
     pointsImg[0][1] =cv::Point2d(598.747,522.755);
     pointsImg[1][1] =cv::Point2d(601.263,277.251);
     pointsImg[0][2] =cv::Point2d(297.202,596.445);
     pointsImg[1][2] =cv::Point2d(902.803,203.551);
     pointsImg[0][3] =cv::Point2d(752.379,154.849);
     pointsImg[1][3] =cv::Point2d(447.62,645.164);
     pointsImg[0][4] =cv::Point2d(495.102,623.967);
     pointsImg[1][4] =cv::Point2d(704.888,176.026);
     pointsImg[0][5] =cv::Point2d(416.875,579.781);
     pointsImg[1][5] =cv::Point2d(783.133,220.231);
     pointsImg[0][6] =cv::Point2d(715.244,387.004);
     pointsImg[1][6] =cv::Point2d(484.746,412.996);
     pointsImg[0][7] =cv::Point2d(752.476,468.349);
     pointsImg[1][7] =cv::Point2d(447.522,331.649);
     pointsImg[0][8] =cv::Point2d(669.711,118.73);
     pointsImg[1][8] =cv::Point2d(530.277,681.28);
     pointsImg[0][9] =cv::Point2d(378.904,468.993);
     pointsImg[1][9] =cv::Point2d(821.094,331.008);
     pointsImg[0][10] =cv::Point2d(659.707,638.096);
     pointsImg[1][10] =cv::Point2d(540.278,161.908);
     pointsImg[0][11] =cv::Point2d(695.208,224.112);
     pointsImg[1][11] =cv::Point2d(504.788,575.891);
     pointsImg[0][12] =cv::Point2d(856.609,488.364);
     pointsImg[1][12] =cv::Point2d(343.392,311.641);
     pointsImg[0][13] =cv::Point2d(287.061,246.871);
     pointsImg[1][13] =cv::Point2d(912.934,553.124);
     pointsImg[0][14] =cv::Point2d(665.78,578.931);
     pointsImg[1][14] =cv::Point2d(534.219,221.064);
     pointsImg[0][15] =cv::Point2d(656.704,796.93);
     pointsImg[1][15] =cv::Point2d(543.296,3.07347);
     pointsImg[0][16] =cv::Point2d(445.083,487.07);
     pointsImg[1][16] =cv::Point2d(754.914,312.939);
     pointsImg[0][17] =cv::Point2d(678.71,441.353);
     pointsImg[1][17] =cv::Point2d(521.275,358.64);
     pointsImg[0][18] =cv::Point2d(502.716,188.403);
     pointsImg[1][18] =cv::Point2d(697.285,611.591);
     pointsImg[0][19] =cv::Point2d(995.513,175.5);
     pointsImg[1][19] =cv::Point2d(204.483,624.491);
     pointsImg[0][20] =cv::Point2d(259.615,861.538);
     pointsImg[1][20] =cv::Point2d(940.392,-61.5342);
     pointsImg[0][21] =cv::Point2d(580.05,568.474);
     pointsImg[1][21] =cv::Point2d(619.963,231.539);
     pointsImg[0][22] =cv::Point2d(789.256,412.983);
     pointsImg[1][22] =cv::Point2d(410.738,387.027);
     pointsImg[0][23] =cv::Point2d(734.535,569.494);
     pointsImg[1][23] =cv::Point2d(465.471,230.499);
     pointsImg[0][24] =cv::Point2d(405.849,430.748);
     pointsImg[1][24] =cv::Point2d(794.142,369.25);
     pointsImg[0][25] =cv::Point2d(735.263,143.643);
     pointsImg[1][25] =cv::Point2d(464.731,656.343);
     pointsImg[0][26] =cv::Point2d(313.653,416.403);
     pointsImg[1][26] =cv::Point2d(886.349,383.603);
     pointsImg[0][27] =cv::Point2d(774.994,210.831);
     pointsImg[1][27] =cv::Point2d(425.015,589.168);
     pointsImg[0][28] =cv::Point2d(442.622,386.411);
     pointsImg[1][28] =cv::Point2d(757.38,413.588);
     pointsImg[0][29] =cv::Point2d(287.422,377.185);
     pointsImg[1][29] =cv::Point2d(912.582,422.816);
     pointsImg[0][30] =cv::Point2d(476.805,480.406);
     pointsImg[1][30] =cv::Point2d(723.184,319.598);
     pointsImg[0][31] =cv::Point2d(631.083,202.738);
     pointsImg[1][31] =cv::Point2d(568.911,597.258);
      
     // fill visibility (all points are visible)
     visibility.resize(NCAMS);
     for(int i=0; i<NCAMS; i++)  {
       visibility[i].resize(NPOINTS);       
       for(int j=0; j<NPOINTS; j++) visibility[i][j]=1;
     }

    // fill camera intrinsics (same intrinsics for all cameras)
    cameraMatrix.resize(NCAMS);
    for(int i=0; i<NCAMS; i++) {
      cameraMatrix[i] = cv::Mat::eye(3,3,CV_64FC1);
      cameraMatrix[i].ptr<double>(0)[0]=cameraMatrix[i].ptr<double>(0)[4]=1000.;
      cameraMatrix[i].ptr<double>(0)[2]=600.;cameraMatrix[i].ptr<double>(0)[5]=400.;
    }
   
    // fill distortion (assume no distortion)
    distCoeffs.resize(NCAMS);
    for(int i=0; i<NCAMS; i++) distCoeffs[i] = cv::Mat(5,1,CV_64FC1, cv::Scalar::all(0));
     
    // fill rotation (rotation around Z axis)
    R.resize(NCAMS);
    for(int i=0; i<NCAMS; i++) {
      R[i] = cv::Mat(3,1,CV_64FC1,cv::Scalar::all(0));
      R[i].ptr<double>(0)[2] = double(i)*2.0944;
    }     
          
    // fill translation (3 units away in camera Z axis)
    T.resize(NCAMS);
    for(int i=0; i<NCAMS; i++) {
      T[i] = cv::Mat(3,1,CV_64FC1,cv::Scalar::all(0));
      T[i].ptr<double>(0)[2] = 3.;
    }
 /***********************************/

 
 /****** RUN BUNDLE ADJUSTMENT ******/
    cvsba::Sba sba;
    sba.run(points3D,  pointsImg,  visibility,  cameraMatrix,  R,  T, distCoeffs);
    
    std::cout<<"Initial error="<<sba.getInitialReprjError()<<". Final error="<<sba.getFinalReprjError()<<std::endl;
 /***********************************/
    
    return 0;
}
