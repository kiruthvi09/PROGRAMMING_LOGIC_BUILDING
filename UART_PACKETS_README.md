#AIM 
TO Process the RECEIVED UART PACKETS.

#STEPS TO SOLVE
1.Write down I/P and O/P as below from the problem clearly.
2.DRAW A FLOW DIAGRAM
3.FIGURE OUT THE ALGORITHM
4.TEST IT OUT WITH EDGE CASES.
5.Finally write the code.

#INPUT
1. UART_PACKET_ARRAY - AA 05 20 41 62 75 96 CE 
byte[0] - start byte Constanst
byte[1]- data_Length
byte[2]- byte[n]- data 
byte[n-1] - Check sum  byte (add all the data bytes and (sum % 256), we get the CS.

#O/P
1.Check start byte if AA proceed further or stop.
2.check  byte[1] and store it as payload Length.
3.check for the FRAME SIZE exact same proceed or provide error and discard.
4.Then Extract data bytes and CS Byte.
5. Calculate CRC and check the CRC is valid from the obtained frame.




#PROBLEMS FACED
#PROBLEM 1
1.ARRAY Index mistake check it properly.

#SOLUTION 1
1.REMEMBER ARRAY ALWAYS STARTS WITH "INDEX 0" keep that in mind while storing data in array.
2.Check for proper bound for the FOR LOOP.

#IMPORTANT PROBLEM
2.INITIALLY CREATED PROGRAM EXPECTING TO RECEIVE THE FRAME DIRECTLY AND STORE IT UNTIL 
'\n' character but it will not work.
#SOLUTION 2
1.First receive the first byte[0] and check is it AA,If not discard.
2.Receive byte[1] and store as payload length and add 3 to it.
That will give the complete Frame LENGTH.
3.Then receive payload or data and Checksum.
4.verify checksum and provide acknowledgement.

#TEST code WITH EXAMPLE
EG: I/P : AA 04 12 34 56 78 14
O/P : 
The Calculated CHECKSUM is 14
Check Sum VALID,DATA RECEIVED Successfully. 

 