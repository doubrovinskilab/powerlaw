

void DefaultBarrierForceParameters()
{
  BF.Type= FORCE_BF_NULL;
  BF.N   = 0;

  BF.Bool_Force_line = false;
  BF.Type_Force_line = FUNC_CONSTANT;
  BF.D_min_line  = 0.5;
  BF.C1_line  = 4.0;
  BF.C2_line  = 0.2;

  BF.Bool_Force_point = false;
  BF.Type_Force_point = FUNC_CONSTANT;
  BF.D_min_point = 0.25;
  BF.C1_point = 4.0;
  BF.C2_point = 0.1;

  BF.Bool_Force_triangle = false;
  BF.Type_Force_triangle = FUNC_CONSTANT;
  BF.D_min_triangle = 0.25;
  BF.C1_triangle = 4.0;
  BF.C2_triangle = 0.1;

  BF.Bool_Force_square = false;
  BF.Type_Force_square = FUNC_CONSTANT;
  BF.D_min_square = 0.25;
  BF.C1_square = 4.0;
  BF.C2_square = 0.1;
}


void PrintBarrierForceProperties()
{
  printf("Barrier Force Properties:\n");
  printf("-----------------------------------\n");
  printf("  BF.Type:\t\t%s\n", FORCE_BF_CHAR[BF.Type]);

  if (BF.Type == FORCE_BF_SET_POINTS)    printf("  BF.N:\t\t\t%d\n", BF.N);
  if (BF.Type != FORCE_BF_NULL)
  {
    printf("    BF.Bool_line:\t%s\n", BF.Bool_Force_line ? "true" : "false");
    if (BF.Bool_Force_line)
    {
      printf("      BF.Type_Force_line:\t%s\n", FUNCTION_TYPE_CHAR[BF.Type_Force_line]);
      printf("      BF.D_min_line:\t\t%lf\n", BF.D_min_line);
      printf("      BF.C1_line:\t\t%lf\n", BF.C1_line);
      printf("      BF.C2_line:\t\t%lf\n", BF.C2_line);
    }
    printf("    BF.Bool_point: %s\n", BF.Bool_Force_point ? "true" : "false");
    if (BF.Bool_Force_point)
    {
      printf("      BF.Type_Force_point:\t%s\n", FUNCTION_TYPE_CHAR[BF.Type_Force_point]);
      printf("      BF.D_min_point:\t\t%lf\n", BF.D_min_point);
      printf("      BF.C1_point:\t\t%lf\n", BF.C1_point);
      printf("      BF.C2_point:\t\t%lf\n", BF.C2_point);
    }
    printf("    BF.Bool_triangle: %s\n", BF.Bool_Force_triangle ? "true" : "false");
    if (BF.Bool_Force_triangle)
    {
      printf("      BF.Type_Force_triangle:\t%s\n", FUNCTION_TYPE_CHAR[BF.Type_Force_triangle]);
      printf("      BF.D_mintrianglet:\t%lf\n", BF.D_min_triangle);
      printf("      BF.C1_triangle:\t\t%lf\n", BF.C1_triangle);
      printf("      BF.C2_triangle:\t\t%lf\n", BF.C2_triangle);
    }
    printf("    BF.Bool_square: %s\n", BF.Bool_Force_square ? "true" : "false");
    if (BF.Bool_Force_square)
    {
      printf("      BF.Type_Force_square:\t%s\n", FUNCTION_TYPE_CHAR[BF.Type_Force_square]);
      printf("      BF.D_min_square:\t%lf\n", BF.D_min_square);
      printf("      BF.C1_square:\t\t%lf\n", BF.C1_square);
      printf("      BF.C2_square:\t\t%lf\n", BF.C2_square);
    }
  }
  printf("\n");
}


bool ReadBarrierForceParameters(const char* str_argv1, const char* str_argv2)
{
  if (strcmp(str_argv1,"-bf_type") == 0){    
    BF.Type = (FORCE_BF_TYPE) atol(str_argv2); 
    return true;}

  if (strcmp(str_argv1,"-bf_bool_force_line") == 0){ 
    if (strcmp(str_argv2,"false") == 0) {     BF.Bool_Force_line = false; }
    else if (strcmp(str_argv2,"true") == 0) {     BF.Bool_Force_line = true; }
    else{  printf("    ERROR!! Unknown bool command '%s'; should be either 'false' or 'true'\n", str_argv1);
           exit(EXIT_FAILURE);}
    return true;}

  if (strcmp(str_argv1,"-bf_type_force_line") == 0){    
    BF.Type_Force_line = (FUNCTION_TYPE) atol(str_argv2); 
    return true;}

  if (strcmp(str_argv1,"-bf_d_min_line") == 0){    
    BF.D_min_line = atof(str_argv2); 
    return true;}

  if (strcmp(str_argv1,"-bf_c1_line") == 0){    
    BF.C1_line = atof(str_argv2); 
    return true;}

  if (strcmp(str_argv1,"-bf_c2_line") == 0){    
    BF.C2_line = atof(str_argv2); 
    return true;}

  if (strcmp(str_argv1,"-bf_bool_force_point") == 0){ 
    if (strcmp(str_argv2,"false") == 0) {     BF.Bool_Force_point = false; }
    else if (strcmp(str_argv2,"true") == 0) {     BF.Bool_Force_point = true; }
    else{  printf("    ERROR!! Unknown bool command '%s'; should be either 'false' or 'true'\n", str_argv1);
           exit(EXIT_FAILURE);}
    return true;}

  if (strcmp(str_argv1,"-bf_type_force_point") == 0){    
    BF.Type_Force_point = (FUNCTION_TYPE) atol(str_argv2);
    return true;}

  if (strcmp(str_argv1,"-bf_d_min_point") == 0){    
    BF.D_min_point = atof(str_argv2);
    return true;}

  if (strcmp(str_argv1,"-bf_c1_point") == 0){    
    BF.C1_point = atof(str_argv2); 
    return true;}

  if (strcmp(str_argv1,"-bf_c2_point") == 0){    
    BF.C2_point = atof(str_argv2); 
    return true;}

  if (strcmp(str_argv1,"-bf_bool_force_triangle") == 0){ 
    if (strcmp(str_argv2,"false") == 0) {     BF.Bool_Force_triangle = false; }
    else if (strcmp(str_argv2,"true") == 0) {     BF.Bool_Force_triangle = true; }
    else{  printf("    ERROR!! Unknown bool command '%s'; should be either 'false' or 'true'\n", str_argv1);
           exit(EXIT_FAILURE);}
    return true;}

  if (strcmp(str_argv1,"-bf_type_force_triangle") == 0){    
    BF.Type_Force_triangle = (FUNCTION_TYPE) atol(str_argv2);
    return true;}

  if (strcmp(str_argv1,"-bf_d_min_triangle") == 0){    
    BF.D_min_triangle = atof(str_argv2); 
    return true;}

  if (strcmp(str_argv1,"-bf_c1_triangle") == 0){    
    BF.C1_triangle = atof(str_argv2); 
    return true;}

  if (strcmp(str_argv1,"-bf_c2_triangle") == 0){    
    BF.C2_triangle = atof(str_argv2);
    return true;}

  if (strcmp(str_argv1,"-bf_bool_force_square") == 0){ 
    if (strcmp(str_argv2,"false") == 0) {     BF.Bool_Force_square = false;}
    else if (strcmp(str_argv2,"true") == 0) {     BF.Bool_Force_square = true;}
    else{  printf("    ERROR!! Unknown bool command '%s'; should be either 'false' or 'true'\n", str_argv1);
           exit(EXIT_FAILURE);}
    return true;}

  if (strcmp(str_argv1,"-bf_type_force_square") == 0){    
    BF.Type_Force_square = (FUNCTION_TYPE) atol(str_argv2); 
    return true;}

  if (strcmp(str_argv1,"-bf_d_min_square") == 0){    
    BF.D_min_square = atof(str_argv2);
    return true;}

  if (strcmp(str_argv1,"-bf_c1_square") == 0){    
    BF.C1_square = atof(str_argv2);
    return true;}

  if (strcmp(str_argv1,"-bf_c2_square") == 0){    
    BF.C2_square = atof(str_argv2);
    return true;}

  if (BF.Type==FORCE_BF_SET_POINTS)
  {
    // File Name for Set of points to recieve Barrier Force
    if (strcmp(str_argv1,"-bf_file_set_points") == 0)
    {  
      char    *fileName;            // file Name for set of point
      fileName = malloc(256);
      sprintf(fileName, "%s", str_argv2);
  
      // Reading the file
      BF.N = GetFileSize(fileName);
      BF.I = (int *)malloc(BF.N*sizeof(int));
      ReadIntFile(fileName, BF.N, BF.I);
      if (BF.N < 1){  
        printf("    ERROR in ReadBarrierForceParameters!! File '%s' is showing only %d points \n", fileName, BF.N);   exit(EXIT_FAILURE);}

      return true;
    }
  }
  
  return false;
}

//===================================================

double CalculateBarrierForceConstant(double D, const double D_min, const double C1, const double C2){
  /* F = C1*/
  return C1;}

double CalculateBarrierForceLinear(double D, const double D_min, const double C1, const double C2){
  /* F = a*D+b where a = (C1-C2)/(D_min-0) and b = C2
    Note: Try to make C2 > C1 in order to have an increase as we approach 0*/
  return ((C1-C2)/(D_min))*D + C2;}

double CalculateBarrierForceExp(double D, const double D_min, const double C1, const double C2){
  /* F = C1*exp((D_min-D)/C2). 
    Note: Try to make C2 < 0.5 in order to have an increase as we approach 0*/
  return C1*exp((D_min-D)/C2);}


//===================================================
inline int AddLineBarrierForce2D(const int p, const int l, double *fx_loc, double *fy_loc)
{
  /* 
    Barrier force from line l on point p (2D)
  */
  double BF_mag; // Magnitude of Barrier force
  double nP1P2x, nP1P2y, nP1P2z, P1P2m; // Normalized line direction vector
  double PP1x, PP1y, PP1z;
  double PP2x, PP2y, PP2z;
  double Prj1, Prj2, Prj3, w1, w2;
  double Nx, Ny;
  double nNx, nNy, nNz, Nm;
  bool Overlps;
  const int p1 = lines.I0[l];
  const int p2 = lines.I1[l];

  if (p==p1 || p == p2) return 0;

  CalcNormalVector(p1, p2, &nP1P2x, &nP1P2y, &nP1P2z, &P1P2m);
  CalcVector(p, p1, &PP1x, &PP1y, &PP1z); 
  CalcVector(p, p2, &PP2x, &PP2y, &PP2z); 

  Prj1 = CalcDotProduct( nP1P2x, nP1P2y, nP1P2z, PP1x, PP1y, PP1z); // PP1. P1P2
  Prj2 = CalcDotProduct( nP1P2x, nP1P2y, nP1P2z, PP2x, PP2y, PP2z); // PP2. P1P2

  Overlps = true;
  if( (Prj1>0 && Prj2>P1P2m) || (Prj2>0 && Prj1>P1P2m) )   Overlps = false;
  if( (Prj1<0 && Prj2<-P1P2m) || (Prj2<0 && Prj1<-P1P2m) ) Overlps = false;

  if (!(Overlps)) return 0;

  // Find the projection point N
  Prj3 = CalcDotProduct( nP1P2x, nP1P2y, nP1P2z, -PP1x, -PP1y, -PP1z); // P1P . P1P2
  Nx = points.x[p] + PP1x + nP1P2x*Prj3;
  Ny = points.y[p] + PP1y + nP1P2y*Prj3;

  // Find the weight for each point
  Prj1 = fabs(Prj1);
  Prj2 = fabs(Prj2);
  w1 = Prj2/(Prj1+Prj2);
  w2 = Prj1/(Prj1+Prj2);

  CalcNormalVector2( Nx, Ny, 0.0, points.x[p], points.y[p], 0.0, &nNx, &nNy, &nNz, &Nm); 
  //if (p==6167) printf("l:%d,Nm:%lf\n",l,Nm);

  if (Nm < BF.D_min_line) // Very close 0.5 um
  {
    BF_mag = BF.Calc_Force_line(Nm, BF.D_min_line, BF.C1_line, BF.C2_line);
    fx_loc[p]  += BF_mag*nNx,     fy_loc[p]  += BF_mag*nNy;
    fx_loc[p1] -= BF_mag*nNx*w1,  fy_loc[p1] -= BF_mag*nNy*w1;
    fx_loc[p2] -= BF_mag*nNx*w2,  fy_loc[p2] -= BF_mag*nNy*w2;
  }
  return 1;
}

inline int AddPointBarrierForce2D(const int p, const int pb, double *fx_loc, double *fy_loc)
{
  /* 
    Barrier force from all lines on point p (2D)
  */
  double BF_mag; // Magnitude of Barrier force
  double nP1P2x, nP1P2y, nP1P2z, P1P2m; // Normalized line direction vector

  if (p==pb) return 0;

  CalcNormalVector(pb, p, &nP1P2x, &nP1P2y, &nP1P2z, &P1P2m);
  if (P1P2m < BF.D_min_point)// Very close 
  {
    BF_mag = BF.Calc_Force_point(P1P2m, BF.D_min_point, BF.C1_point, BF.C2_point)/2.0;
    fx_loc[p]  += BF_mag*nP1P2x,  fy_loc[p]  += BF_mag*nP1P2y; 
    fx_loc[pb] -= BF_mag*nP1P2x,  fy_loc[pb] -= BF_mag*nP1P2y; 
  }
  // Note: We added 1/2 force to p & pb. 
  // ----- Since it the other 1/2 will be added when a new p becomes the old pb (To avoid adding twice)
  return 1;
}

void AddLineBarrierForceUsingBoxes2D(const int p, double *fx_loc, double *fy_loc)
{
  /* 
    Barrier force from all lines in boxes around point 'p' on 'p' (2D)
  */
  int i,j,m,B;
  // Searching All boxes in vacinit
  for(i=-1; i<2; i++) 
  {
    for(j=-1; j<2; j++) 
    {
      B = BoxesCalcIndex(points.x[p], points.y[p], points.z[p], i, j, 0); // Box index

      // Adding line force
      for(m=1; m<boxes.box_lines[B][0]+1; m++)
      {
        const int l = boxes.box_lines[B][m];
        AddLineBarrierForce2D(p, l, fx_loc, fy_loc);
      }
    }
  }
}


void AddPointBarrierForceUsingBoxes2D(const int p, double *fx_loc, double *fy_loc)
{
  /* 
    Barrier force from all points in boxes around point 'p' on 'p' (2D)
  */
  int i,j,m,B;
  // Searching All boxes in vacinit
  for(i=-1; i<2; i++) 
  {
    for(j=-1; j<2; j++)
    {
      B = BoxesCalcIndex(points.x[p], points.y[p], points.z[p], i, j, 0); // Box index

      // Adding the force from points
      for (m=1;m<boxes.box_points[B][0]+1;m++)
      {
        const int pb = boxes.box_points[B][m]; // barrier point
        AddPointBarrierForce2D(p, pb, fx_loc, fy_loc);
      }
    }
  }
}

inline int AddLineBarrierForce3D(const int p, const int l, double *fx_loc, double *fy_loc, double *fz_loc)
{
  /* 
    Barrier force from all lines on point p
  */
  double BF_mag; // Magnitude of Barrier force
  double nP1P2x, nP1P2y, nP1P2z, P1P2m; // Normalized line direction vector
  double PP1x, PP1y, PP1z;
  double PP2x, PP2y, PP2z;
  double Prj1, Prj2, Prj3, w1, w2;
  double Nx, Ny, Nz;
  double nNx, nNy, nNz, Nm;
  bool Overlps;

  const int p1 = lines.I0[l];
  const int p2 = lines.I1[l];

  if (p==p1 || p == p2) return 0;

  CalcNormalVector(p1, p2, &nP1P2x, &nP1P2y, &nP1P2z, &P1P2m);
  CalcVector(p, p1, &PP1x, &PP1y, &PP1z); 
  CalcVector(p, p2, &PP2x, &PP2y, &PP2z); 

  Prj1 = CalcDotProduct( nP1P2x, nP1P2y, nP1P2z, PP1x, PP1y, PP1z); // PP1. nP1P2
  Prj2 = CalcDotProduct( nP1P2x, nP1P2y, nP1P2z, PP2x, PP2y, PP2z); // PP2. nP1P2

  Overlps = true;
  if( (Prj1>0 && Prj2>P1P2m) || (Prj2>0 && Prj1>P1P2m) )   Overlps = false;
  if( (Prj1<0 && Prj2<-P1P2m) || (Prj2<0 && Prj1<-P1P2m) ) Overlps = false;

  if (!(Overlps)) return 0;

  // Find the projection point N
  Prj3 = CalcDotProduct( nP1P2x, nP1P2y, nP1P2z, -PP1x, -PP1y, -PP1z); // P1P . nP1P2
  Nx = points.x[p] + PP1x + nP1P2x*Prj3;
  Ny = points.y[p] + PP1y + nP1P2y*Prj3;
  Nz = points.z[p] + PP1z + nP1P2z*Prj3;

  // Find the weight for each point
  Prj1 = fabs(Prj1);
  Prj2 = fabs(Prj2);
  w1 = Prj2/(Prj1+Prj2);
  w2 = Prj1/(Prj1+Prj2);

  CalcNormalVector2( Nx, Ny, Nz, points.x[p], points.y[p], points.z[p], &nNx, &nNy, &nNz, &Nm); 
  //if (p==6167) printf("l:%d,Nm:%lf\n",l,Nm);

  if (Nm < BF.D_min_line) // Very close 0.5 um
  {
    BF_mag = BF.Calc_Force_line(Nm, BF.D_min_line, BF.C1_line, BF.C2_line);
    fx_loc[p]  += BF_mag*nNx,     fy_loc[p]  += BF_mag*nNy,     fz_loc[p]  += BF_mag*nNz;
    fx_loc[p1] -= BF_mag*nNx*w1,  fy_loc[p1] -= BF_mag*nNy*w1,  fz_loc[p1] -= BF_mag*nNz*w1;
    fx_loc[p2] -= BF_mag*nNx*w2,  fy_loc[p2] -= BF_mag*nNy*w2,  fz_loc[p2] -= BF_mag*nNz*w2;
  }

  return 1;
}

inline int AddPointBarrierForce3D(const int p, const int pb, double *fx_loc, double *fy_loc, double *fz_loc)
{
  /* 
    Barrier force from all points on point p
  */
  double BF_mag; // Magnitude of Barrier force
  double nP1P2x, nP1P2y, nP1P2z, P1P2m; // Normalized line direction vector

  if (p==pb)   return 0;

  CalcNormalVector(pb, p, &nP1P2x, &nP1P2y, &nP1P2z, &P1P2m); // nPbP
  if (P1P2m < BF.D_min_point)// Very close 
  {
    BF_mag = BF.Calc_Force_point(P1P2m, BF.D_min_point, BF.C1_point, BF.C2_point)/2.0;
    fx_loc[p]  += BF_mag*nP1P2x,  fy_loc[p]  += BF_mag*nP1P2y,  fz_loc[p]  += BF_mag*nP1P2z; 
    fx_loc[pb] -= BF_mag*nP1P2x,  fy_loc[pb] -= BF_mag*nP1P2y,  fz_loc[pb] -= BF_mag*nP1P2z; 
  }
  // Note: We added 1/2 force to p & pb. 
  // ----- Since the other 1/2 of the force will be added when a new
  //-----  p becomes the old pb (To avoid adding twice)
  return 1;
}


inline int AddTriangleBarrierForce3D(const int p, const int t, double *fx_loc, double *fy_loc, double *fz_loc)
{  
  /* 
    Barrier force from all triangles on point p
  */
  double BF_mag; // Magnitude of Barrier force
  double PP1x, PP1y, PP1z;
  double Prj1;
  double nNx, nNy, nNz;
  bool Q_in;
  double P1P2x, P1P2y, P1P2z;
  double P1P3x, P1P3y, P1P3z;
  double Qx, Qy, Qz;

  const int p1 = triangles.I0[t];
  const int p2 = triangles.I1[t];
  const int p3 = triangles.I2[t];
  if (p==p1 || p==p2 || p==p3) return 0;

  // STEP 1: Calc plane equation and plane normal vec{n}
  CalcVector(p1, p2, &P1P2x, &P1P2y, &P1P2z); 
  CalcVector(p1, p3, &P1P3x, &P1P3y, &P1P3z); 

  CalcCrossProductNormalzied(P1P2x, P1P2y, P1P2z, P1P3x, P1P3y, P1P3z, &nNx, &nNy, &nNz);

  // Plane equation: nNx.x + nNy.y + nNz.z = b
  //b = nNx*points.x[p1] + nNy*points.x[p1] + nNz*points.x[p1]; 

  // Step 2: Calc vector P1P
  CalcVector(p, p1, &PP1x, &PP1y, &PP1z); 

  // Step 3: Calc P1P.n
  Prj1 = CalcDotProduct( nNx, nNy, nNz, PP1x, PP1y, PP1z); // PP1. nP1P2

  // Step 4: Calc Q from QP= (P1P.n)vec{n}
  Qx = points.x[p] - Prj1*nNx;
  Qy = points.y[p] - Prj1*nNy;
  Qz = points.z[p] - Prj1*nNz;

  // Step 5: Check if Q in Triangle
  Q_in = checkIfPointIn3DTriangle( Qx, Qy, Qz, 
                            points.x[p1], points.y[p1], points.z[p1],
                            points.x[p2], points.y[p2], points.z[p2],
                            points.x[p3], points.y[p3], points.z[p3]  );

  // Step 6: If Q in Triangle ==> Check the distance
  if (Q_in)
    if (Prj1 < BF.D_min_triangle)// Very close 
    {
      BF_mag = BF.Calc_Force_triangle(Prj1, BF.D_min_triangle, BF.C1_triangle, BF.C2_triangle);
      fx_loc[p]  += BF_mag*nNx,  fy_loc[p]  += BF_mag*nNy,  fz_loc[p]  += BF_mag*nNz; 
    }

  return 1;
}

inline int AddSquareBarrierForce3D(const int p, const int s, double *fx_loc, double *fy_loc, double *fz_loc)
{  
  /* 
    Barrier force from all squares on point p
  */

  double BF_mag; // Magnitude of Barrier force
  double PP1x, PP1y, PP1z;
  double Prj1;
  double nNx, nNy, nNz;
  bool Q_in;
  double P1P2x, P1P2y, P1P2z;
  double P1P3x, P1P3y, P1P3z;
  double Qx, Qy, Qz;

  const int p1 = squares.I0[s];
  const int p2 = squares.I1[s];
  const int p3 = squares.I2[s];
  const int p4 = squares.I2[s];
  if (p==p1 || p==p2 || p==p3 || p==p4) return 0;

  // STEP 1: Calc plane equation and plane normal vec{n}
  CalcVector(p1, p2, &P1P2x, &P1P2y, &P1P2z); 
  CalcVector(p1, p3, &P1P3x, &P1P3y, &P1P3z); 

  CalcCrossProductNormalzied(P1P2x, P1P2y, P1P2z, P1P3x, P1P3y, P1P3z, &nNx, &nNy, &nNz);

  // Step 2: Calc vector P1P
  CalcVector(p, p1, &PP1x, &PP1y, &PP1z); 

  // Step 3: Calc P1P.n
  Prj1 = CalcDotProduct( nNx, nNy, nNz, PP1x, PP1y, PP1z); // PP1. nP1P2

  // Step 4: Calc Q from QP= (P1P.n)vec{n}
  Qx = points.x[p] - Prj1*nNx;
  Qy = points.y[p] - Prj1*nNy;
  Qz = points.z[p] - Prj1*nNz;

  // Step 5: Check if Q in Square
  Q_in = checkIfPointIn3DSquare(      Qx,           Qy,           Qz, 
                            points.x[p1], points.y[p1], points.z[p1],
                            points.x[p2], points.y[p2], points.z[p2],
                            points.x[p3], points.y[p3], points.z[p3],  
                            points.x[p4], points.y[p4], points.z[p4] );

  // Step 6: If Q in Square ==> Check the distance
  if (Q_in)
    if (Prj1 < BF.D_min_square)// Very close 
    {
      BF_mag = BF.Calc_Force_square(Prj1, BF.D_min_square, BF.C1_square, BF.C2_square);
      fx_loc[p]  += BF_mag*nNx,  fy_loc[p]  += BF_mag*nNy,  fz_loc[p]  += BF_mag*nNz; 
    }
  return 1;
}

void AddLineBarrierForceUsingBoxes3D(const int p, double *fx_loc, double *fy_loc, double *fz_loc)
{
  /* 
    Barrier force from all lines on point p
  */

  int B,i,j,k,m;

  // Searching All boxes in vacinity
  for(i=-1; i<2; i++){
    for(j=-1; j<2; j++) {
      for(k=-1; k<2; k++) {
        B = BoxesCalcIndex(points.x[p], points.y[p], points.z[p], i, j, k); // Box index
        for(m=1; m<boxes.box_lines[B][0]+1; m++)  {
          const int l = boxes.box_lines[B][m];
          AddLineBarrierForce3D(p, l, fx_loc, fy_loc, fz_loc); }
      }
    }
  }
}

void AddPointBarrierForceUsingBoxes3D(const int p, double *fx_loc, double *fy_loc, double *fz_loc)
{
  /* 
    Barrier force from all points on point p
  */
  int B,i,j,k,m;

  for(i=-1; i<2; i++) {
    for(j=-1; j<2; j++) {
      for(k=-1; k<2; k++)
      {
        B = BoxesCalcIndex(points.x[p], points.y[p], points.z[p], i, j, k); // Box index
        for (m=1;m<boxes.box_points[B][0]+1;m++) {
          const int pb = boxes.box_points[B][m]; // barrier point
          AddPointBarrierForce3D( p, pb, fx_loc, fy_loc, fz_loc);  }
      }
    }
  }
}

void AddTriangleBarrierForceUsingBoxes3D(const int p, double *fx_loc, double *fy_loc, double *fz_loc)
{  
  /* 
    Barrier force from all triangles on point p
  */
  int B,i,j,k,m;

  for(i=-1; i<2; i++) {
    for(j=-1; j<2; j++) {
      for(k=-1; k<2; k++)
      {
        B = BoxesCalcIndex(points.x[p], points.y[p], points.z[p], i, j, k); // Box index
        for (m=1;m<boxes.box_triangles[B][0]+1;m++)
        {
          const int t = boxes.box_triangles[B][m];
          AddTriangleBarrierForce3D( p, t, fx_loc, fy_loc, fz_loc);
        }
      }
    }
  }
}

void AddSquareBarrierForceUsingBoxes3D(const int p, double *fx_loc, double *fy_loc, double *fz_loc)
{  
  /* 
    Barrier force from all squares on point p
  */
  int B,i,j,k,m;

  for(i=-1; i<2; i++) {
    for(j=-1; j<2; j++) {
      for(k=-1; k<2; k++)
      {
        B = BoxesCalcIndex(points.x[p], points.y[p], points.z[p], i, j, k); // Box index

        // Adding the force from points
        for (m=1;m<boxes.box_squares[B][0]+1;m++)
        {
          const int s = boxes.box_squares[B][m];
          AddSquareBarrierForce3D(p, s, fx_loc, fy_loc, fz_loc);
        }
      }
    }
  }
}



//==============================================================

void CalculataBarrierForce3D()
{

  #pragma omp parallel
  {
    int p, p_start, p_end, omp_rank = (int) omp_get_thread_num();

    double *fx_loc = (double *)calloc(forces.N,sizeof(double));
    double *fy_loc = (double *)calloc(forces.N,sizeof(double));
    double *fz_loc = (double *)calloc(forces.N,sizeof(double));
    
    GetLimitsOMPLoop(points.N, omp_nthreads, omp_rank, &p_start, &p_end);
    
    // Looping over all points to add Line Barrier Force
    if(BF.Bool_Force_line)
      for(p=p_start; p< p_end; p++) {
        AddLineBarrierForceUsingBoxes3D(p, fx_loc, fy_loc, fz_loc); }

    // Looping over all points to add Point Barrier Force
    if(BF.Bool_Force_point)
      for(p=p_start; p< p_end; p++) {
        AddPointBarrierForceUsingBoxes3D(p, fx_loc, fy_loc, fz_loc); }
    
    // Looping over all points to add Triangle Barrier Force
    if(BF.Bool_Force_triangle)
      for(p=p_start; p< p_end; p++) {
        AddPointBarrierForceUsingBoxes3D(p, fx_loc, fy_loc, fz_loc); }
    
    // Looping over all points to add Square Barrier Force
    if(BF.Bool_Force_square)
      for(p=p_start; p< p_end; p++) {
        AddSquareBarrierForceUsingBoxes3D(p, fx_loc, fy_loc, fz_loc); }
      
    #pragma omp critical
    {
      for(p=0; p<points.N; p++)
        {
          forces.x[p] += fx_loc[p];
          forces.y[p] += fy_loc[p]; 
          forces.z[p] += fz_loc[p]; 
        }
    }
    free(fx_loc);
    free(fy_loc);
    free(fz_loc);
  }
}



void CalculataBarrierForce2D()
{

  #pragma omp parallel
  {

    int p, p_start, p_end, omp_rank = (int) omp_get_thread_num();

    double *fx_loc = (double *)calloc(forces.N,sizeof(double));
    double *fy_loc = (double *)calloc(forces.N,sizeof(double));
    
    GetLimitsOMPLoop(points.N, omp_nthreads, omp_rank, &p_start, &p_end);
    
    // Looping over all points
    if(BF.Bool_Force_line)
      for(p=p_start; p< p_end; p++){
        AddLineBarrierForceUsingBoxes2D(p, fx_loc, fy_loc); }

    // Looping over all points
    if(BF.Bool_Force_point)
      for(p=p_start; p< p_end; p++) {
        AddPointBarrierForceUsingBoxes2D(p, fx_loc, fy_loc); }
    
    #pragma omp critical
    {
      for(p=0; p<points.N; p++)
        {
          forces.x[p] += fx_loc[p];
          forces.y[p] += fy_loc[p]; 
        }
    }

    free(fx_loc);
    free(fy_loc);
  }
}


void CalculataBarrierForce3DForSetOfPoints()
{
  #pragma omp parallel
  {
    for (int i=0; i<BF.N; i++)
    {
      const int pi = BF.I[i];

      double *fx_loc = (double *)calloc(forces.N,sizeof(double));
      double *fy_loc = (double *)calloc(forces.N,sizeof(double));
      double *fz_loc = (double *)calloc(forces.N,sizeof(double));

      if(BF.Bool_Force_line)   {
        int l, l_start, l_end, omp_rank = (int) omp_get_thread_num();
        GetLimitsOMPLoop(lines.N, omp_nthreads, omp_rank, &l_start, &l_end);
        for (l=l_start; l<l_end; l++)  AddLineBarrierForce3D(pi, l, fx_loc, fy_loc, fz_loc);    }
    
      if(BF.Bool_Force_point)   {
        int pb, pb_start, pb_end, omp_rank = (int) omp_get_thread_num();
        GetLimitsOMPLoop(points.N, omp_nthreads, omp_rank, &pb_start, &pb_end);
        for (pb=pb_start; pb<pb_end; pb++)  AddPointBarrierForce3D(pi, pb, fx_loc, fy_loc, fz_loc);    }

      if(BF.Bool_Force_triangle)   {
        int t, t_start, t_end, omp_rank = (int) omp_get_thread_num();
        GetLimitsOMPLoop(triangles.N, omp_nthreads, omp_rank, &t_start, &t_end);
        for (t=t_start; t<t_end; t++)  AddTriangleBarrierForce3D(pi, t, fx_loc, fy_loc, fz_loc);    }

      if(BF.Bool_Force_square)   {
        int s, s_start, s_end, omp_rank = (int) omp_get_thread_num();
        GetLimitsOMPLoop(squares.N, omp_nthreads, omp_rank, &s_start, &s_end);
        for (s=s_start; s<s_end; s++)  AddSquareBarrierForce3D(pi, s, fx_loc, fy_loc, fz_loc);    }

      #pragma omp critical
      {
        for(int p=0; p<points.N; p++)
          {
            forces.x[p] += fx_loc[p];
            forces.y[p] += fy_loc[p]; 
            forces.z[p] += fz_loc[p]; 
          }
      }
      free(fx_loc);
      free(fy_loc);
      free(fz_loc);
    }
  } 
}



void BarrierForcesNull(){}

//=========================================================================================

void ChooseBarrierForcesFunc()
{
  printf("Choosing the barrier force function\n"); 

  if(BF.Type == FORCE_BF_NULL)
  {
    printf("  No barrier force function chosen\n");  
    BF.Func=BarrierForcesNull;
  }
  else 
  {
    if(BF.Bool_Force_line)
    {
      if (BF.Type_Force_line == FUNC_CONSTANT){
        printf("  Barrier force function for lines is constant equal to F = %lf\n", BF.C1_line); 
        BF.Calc_Force_line = CalculateBarrierForceConstant;}
      else if (BF.Type_Force_line == FUNC_LINEAR){
        printf("  Barrier force function for lines is linear equal to F = ((%lf-%lf)/(%lf - 0))D + %lf\n", BF.C1_line, BF.C2_line, BF.D_min_line, BF.C2_line); 
        BF.Calc_Force_line = CalculateBarrierForceLinear;}
      else if (BF.Type_Force_line == FUNC_EXP){
        printf("  Barrier force function for lines is exponential equal to F = %lf exp((%lf - D)/%lf)\n", BF.C1_line, BF.D_min_line, BF.C2_line); 
        BF.Calc_Force_line = CalculateBarrierForceExp;}
      else{
        printf("  ERROR!! Barrier force function for lines is undefined\n");
        exit(EXIT_FAILURE);}
    }
      
    if(BF.Bool_Force_point)
    {
      if (BF.Type_Force_point == FUNC_CONSTANT){
        printf("  Barrier force function for points is constant equal to F = %lf\n", BF.C1_point); 
        BF.Calc_Force_point = CalculateBarrierForceConstant;}
      else if (BF.Type_Force_point == FUNC_LINEAR){
        printf("  Barrier force function for points is linear equal to F = ((%lf-%lf)/(%lf - 0))D + %lf\n", BF.C1_point, BF.C2_point, BF.D_min_point, BF.C2_point); 
        BF.Calc_Force_point = CalculateBarrierForceLinear;}
      else if (BF.Type_Force_point == FUNC_EXP){
        printf("  Barrier force function for points is exponential equal to F = %lf exp((%lf - D)/%lf)\n", BF.C1_point, BF.D_min_point, BF.C2_point); 
        BF.Calc_Force_point = CalculateBarrierForceExp;}
      else{
        printf("  ERROR!! Barrier force function for points is undefined\n");
        exit(EXIT_FAILURE);}
    }

    if(BF.Bool_Force_triangle)
    {
      if (BF.Type_Force_triangle == FUNC_CONSTANT){
        printf("  Barrier force function for triangles is constant equal to F = %lf\n", BF.C1_triangle); 
        BF.Calc_Force_triangle = CalculateBarrierForceConstant;}
      else if (BF.Type_Force_triangle == FUNC_LINEAR){
        printf("  Barrier force function for triangles is linear equal to F = ((%lf-%lf)/(%lf - 0))D + %lf\n", BF.C1_triangle, BF.C2_triangle, BF.D_min_triangle, BF.C2_triangle); 
        BF.Calc_Force_triangle = CalculateBarrierForceLinear;}
      else if (BF.Type_Force_triangle == FUNC_EXP){
        printf("  Barrier force function for triangles is exponential equal to F = %lf exp((%lf - D)/%lf)\n", BF.C1_triangle, BF.D_min_triangle, BF.C2_triangle); 
        BF.Calc_Force_triangle = CalculateBarrierForceExp;}
      else{
        printf("  ERROR!! Barrier force function for triangles is undefined\n");
        exit(EXIT_FAILURE);}
    }

    if(BF.Bool_Force_square)
    {
      if (BF.Type_Force_square == FUNC_CONSTANT){
        printf("  Barrier force function for squares is constant equal to F = %lf\n", BF.C1_square); 
        BF.Calc_Force_square = CalculateBarrierForceConstant;}
      else if (BF.Type_Force_square == FUNC_LINEAR){
        printf("  Barrier force function for squares is linear equal to F = ((%lf-%lf)/(%lf - 0))D + %lf\n", BF.C1_square, BF.C2_square, BF.D_min_square, BF.C2_square); 
        BF.Calc_Force_square = CalculateBarrierForceLinear;}
      else if (BF.Type_Force_square == FUNC_EXP){
        printf("  Barrier force function for squares is exponential equal to F = %lf exp((%lf - D)/%lf)\n", BF.C1_square, BF.D_min_square, BF.C2_square); 
        BF.Calc_Force_square = CalculateBarrierForceExp;}
      else{
        printf("  ERROR!! Barrier force function for squares is undefined\n");
        exit(EXIT_FAILURE);}
    }

    printf("Choosing the barrier force method: \n"); 
    if (BF.Type == FORCE_BF_NULL)
    {
      printf("  No barrier force function chosen\n"); 
      BF.Func=BarrierForcesNull;
    }
    else if ((BF.Type == FORCE_BF_ALL_POINTS) && (BF.Bool_Force_line || BF.Bool_Force_point || BF.Bool_Force_triangle || BF.Bool_Force_square))
    {
      if (DIM == 2){
        printf("  2D barrier force function for all points chosen\n"); 
        BF.Func = CalculataBarrierForce2D;}
      else if (DIM == 3){
        printf("  3D barrier force function for all points chosen\n"); 
        BF.Func = CalculataBarrierForce3D;}
      else{
        printf("  ERROR!! No barrier force function chosen. DIM=%d is undefined\n", DIM);    
        BF.Func = CalculateNullForce;
        exit(EXIT_FAILURE);}
    }
    else if ((BF.Type == FORCE_BF_SET_POINTS) && (BF.Bool_Force_line || BF.Bool_Force_point || BF.Bool_Force_triangle || BF.Bool_Force_square))
    {
      if (DIM == 3){
        printf("  3D barrier force function for a certain set of points chosen\n"); 
        BF.Func = CalculataBarrierForce3DForSetOfPoints;}
      else{
        printf("  ERROR!! No barrier force function chosen. DIM=%d is undefined\n", DIM);    
        BF.Func = CalculateNullForce;
        exit(EXIT_FAILURE);}
    }
    else
    {
      printf("  ERROR!! Barrier force function can not be chosen\n");      exit(EXIT_FAILURE);
    }
  }
}

void ForcesAddBarrierForces(){ BF.Func();}
