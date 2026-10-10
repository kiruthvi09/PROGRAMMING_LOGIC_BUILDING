#include <stdio.h>

typedef enum {
INVALID =0,
LOW,
MEDIUM,
HIGH,
CRITICAL
}stage;

stage getStage(int adc_val);

void findMaximumAndMinimum(int *arr,int arrSize,int* maximum,int* minimum){
    *maximum = arr[0];
    *minimum = arr[0];
    for(int i=0;i<arrSize;i++ ){
        if(arr[i]>*maximum){
            *maximum = arr[i];
        }
        if(arr[i]< *minimum){
            *minimum = arr[i];
        }
    }
}

void findAverage(int* arr,int arrSize,int* Average){
    *Average=0;
    for(int i=0;i<arrSize;i++){
        *Average+=arr[i];
    }
  *Average = *Average/arrSize;
}

void findStageOfReadings(int* arr,int arrSize,int* LowCount,int *MediumCount,
int *HighCount,int* CriticalCount){
    stage current_stage =INVALID;
    for(int i=0;i<arrSize;i++){
        current_stage = getStage(arr[i]);
        if(current_stage == LOW){
            (*LowCount)++;
        }
        else if(current_stage == MEDIUM){
            (*MediumCount)++;
        }
        else if(current_stage == HIGH){
            (*HighCount)++;
        }
        else if(current_stage == CRITICAL) { 
        (*CriticalCount)++;
    }
}
}

void findLongSequence(int* arr,int arr_size,int *maximum,stage *Maximum_stage){
    int current=0;
    stage current_stage =INVALID;
    stage current_read_stage =INVALID;
    for(int i=0;i<arr_size;i++){
         current_read_stage =  getStage(arr[i]) ;
        if(current_read_stage == current_stage){
          current++;
        }
        else{
             current_stage = current_read_stage;
             current=1;
            
        }
        if (current > *maximum){
                *maximum = current;
                *Maximum_stage=current_stage;
                
            }
}
}

stage getStage(int adc_val){
    if(adc_val < 0  adc_val >255) return INVALID;
    
    else if(adc_val <=255) return LOW;
    
    else if(adc_val <= 511) return MEDIUM;
    
    else if(adc_val <=767)  return HIGH;
    
    else if(adc_val <=1023) return CRITICAL;
    
    
}

int main(){
    int arr_Size=0;
    int min=0;
    int max=0;
    int avg=0;
    int LongestSeqCnt=0;
    stage LongestSeqStage= INVALID;
    int L_count=0,M_count=0,H_count=0,C_count=0;
    
  printf("\nEnter the No of ADC values you need:\t ");
  scanf("%d",&arr_Size);
  if(arr_Size <= 0){
      printf("Enter a valid count");
      return 0;
  }
    int arr[arr_Size];
    printf("\nEnter the %d ADC values:\t",arr_Size);
    for(int i=0;i<arr_Size;i++){
        scanf("%d",&arr[i]);
    }
    
    findMaximumAndMinimum(arr,arr_Size,&max,&min);
    findAverage(arr,arr_Size,&avg);
    findStageOfReadings(arr,arr_Size,&L_count,&M_count,&H_count,&C_count);
    findLongSequence(arr,arr_Size,&LongestSeqCnt,&LongestSeqStage);
    printf("\nMaximum   : %d",max);
    printf("\nMinimum   : %d",min);
    printf("\nAverage   : %d",avg);
    printf("\nLOW       : %d",L_count);
    printf("\nMEDIUM    : %d",M_count);
    printf("\nHIGH      : %d",H_count);
    printf("\nCRITICAL  : %d",C_count);
    if(LongestSeqStage == LOW){
        printf("\nThe Longest Sequence stage is LOW with count %d",LongestSeqCnt);
    }
    else if(LongestSeqStage == MEDIUM){
        printf("\nThe Longest Sequence stage is MEDIUM with count %d",LongestSeqCnt);
    }
    else if(LongestSeqStage == HIGH){
        printf("\nThe Longest Sequence stage is HIGH with count %d",LongestSeqCnt);
    }
    else if(LongestSeqStage == CRITICAL){
        printf("\nThe Longest Sequence stage is CRITICAL with count %d",LongestSeqCnt);
    }
   
      
}