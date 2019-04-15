#include "72832Core.h"

struct RAMP{
    public:
    int ChangePct; // The amout of Pct change per loop
    int ChangeMsec; // The amount of time in between loops

    int ReqPct = 0; // Used to request Pct value change
    int NowPct = 0; // Pct output
    int MinPct; // Used as moveing up StillSpeed
    int MaxPct; // the max pct value

    int EndWait;
    int Correction;

    int RampTask;
    int RampDistance;

}; // End of task

void RampInit(struct RAMP *controller, int ChangePct=1,int ChangeMsec=8,int MaxPct=75,int MinPct=0,int EndWait=200,int Correction=1){
    // ChangePct,ChangeMsec,MaxPct
    controller->ChangePct=ChangePct;
    controller->ChangeMsec=ChangeMsec;

    controller->MaxPct=MaxPct;
    controller->MinPct=MinPct;

    controller->EndWait=EndWait;
    controller->Correction=Correction;
}

int RampCompute(struct RAMP *controller,double Distance,int Feedback){

    double Direction=SGN(Distance);
    controller->RampTask = 0;

    // Is it there yet?
    if(ABS(Feedback)<ABS(Distance)){

        if(Distance>controller->ReqPct){
            controller->ReqPct=controller->MaxPct;
            controller->RampTask=0;
        }else if(controller->NowPct==controller->MaxPct && controller->RampTask==0){
            controller->RampDistance = Feedback;
            controller->RampTask=1;
        }else if(controller->NowPct==controller->MaxPct && controller->RampTask==1){
            if(Feedback>=(Distance-controller->RampDistance)){
                controller->ReqPct=controller->MinPct;
                controller->RampTask=-1;
            }
        }

        if(controller->ReqPct>controller->NowPct){ // Ramp up
            controller->NowPct+=controller->ChangePct;
        }else if(controller->ReqPct<controller->NowPct){ // Ramp down
            controller->NowPct-=controller->ChangePct;
        }

        // Limit Pct
        if(controller->NowPct>controller->MaxPct)
            controller->NowPct=controller->MaxPct;

        if(controller->NowPct<-controller->MaxPct)
            controller->NowPct=-controller->MaxPct;

        if(controller->NowPct>-controller->MinPct && controller->NowPct<controller->MinPct)
            controller->NowPct=0;

        vex::task::sleep(controller->ChangeMsec);

        if(controller->NowPct!=0)
            return controller->NowPct;
    }else{
        vex::task::sleep(controller->EndWait);
        return 0;
    }
}