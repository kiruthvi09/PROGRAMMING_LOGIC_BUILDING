#include <stdio.h>
#include <stdint.h>

#define packet_size 50
#define START_BYTE 0xAA

typedef enum{
    START_BYTE_ERROR =0,
    SUCCESS,
    INVALID_FRAME,
    INVALID_CS,
    VALID_CS,
} Status;

Status process_UART_RX_Data(uint8_t* Rx_arr,int size,int payloadLen,
                                     char* payload,uint8_t* rx_cs);
uint8_t calculateCheckSum(char *payload,int payloadLen);
Status isValidCheckSum(uint8_t RX_CS,uint8_t calc_CS);

int main(){
    uint8_t UART_arr [packet_size]={0};
    int payloadLen ;
    int Rx_pktLen =0;
    
    uint8_t Rx_CS =0;
    unsigned int temp;
    printf("Enter the UART start Byte: ");
    scanf("%2X",&temp);
    UART_arr[0]= (uint8_t)temp;
    printf("\nEnter the Payload Length :");
    scanf("%2X",&temp);
    UART_arr[1]= (uint8_t)temp;
    payloadLen = UART_arr[1];
    Rx_pktLen = payloadLen+3;
     
    uint8_t payload[payloadLen] ;
    printf("\nEnter the Payload :");
    for(int i=0;i<payloadLen+1;i++){
        scanf("%2X",&temp);
        UART_arr[i+2] =(uint8_t) temp;
    }

    
    
  
    
    
   Status process_result = process_UART_RX_Data(UART_arr,Rx_pktLen,payloadLen,payload,&Rx_CS);
    if(process_result == START_BYTE_ERROR) printf("\nINVALID Start byte,Discard The Frame ");
    else if(process_result == INVALID_FRAME) printf("\nINVALID FRAME SIZE,Discard The Frame");
   else if(process_result == SUCCESS){
     uint8_t calculated_CS = calculateCheckSum(payload,payloadLen);
     printf("The calculated checkSum is %2X",calculated_CS);
    Status CS_Validity = isValidCheckSum(Rx_CS,calculated_CS); 
     if(CS_Validity == INVALID_CS) printf("\nCheck Sum Error,CURROPTED DATA.");
    else printf("\nCheck Sum VALID,DATA Received Successfully");
   }
   
    
    
   


}

Status process_UART_RX_Data(uint8_t* Rx_arr,int size,int payloadLen,
                                     char* payload,uint8_t* rx_cs){
            
           if(size >= payloadLen+3){
           
            if(!(Rx_arr[0] == START_BYTE)){
             return START_BYTE_ERROR;   
            } 
            
            for(int i=0;i<payloadLen;i++){
                payload[i]=Rx_arr[i+2];
                
            }
            
            *rx_cs = Rx_arr[size-1];
            return SUCCESS;
           }
           else return INVALID_FRAME;
           
           
                                         
                                     }
uint8_t calculateCheckSum(char *payload,int payloadLen){
    uint8_t checkSum = 0x00;
    for(int i=0;i<payloadLen;i++){
        checkSum += payload[i];
    }
    
    checkSum = checkSum % 256;
    
  return checkSum;
}

Status isValidCheckSum(uint8_t RX_CS,uint8_t calc_CS){
    if(RX_CS == calc_CS){
        return VALID_CS;
    }
    else return INVALID_CS;
}
    