double ABS(double Var){//use "#include <cmath>" and "std::abs()"instead
    if(Var<0)  Var=Var*(-1);
    return Var;
}
int SGN(double Var){
    if(Var>0)       Var=1;
    else if(Var<0)  Var=-1;
    else            Var=0;
    return Var;
}
void EndTimeSlice(int EndWait=5){//add posible callback during waiting with while loop via background task
    vex::task::sleep(EndWait);
}
void limit(int& Val,int minVal=-100,int maxVal=100){//add option to not ref var
    if(Val<minVal) Val=minVal;
    if(Val>maxVal) Val=maxVal;
}
double MAX(double v1, double v2){
    if(v1>v2)   return v1;
    else        return v2;
}