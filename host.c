#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>



  int main(int argc , char **argv)
  {


  int host1,lan1;
  int start_time,period;
  int i=1,k=0;
  int trem=0,loop_val=0,count=10;
  char type[15];

  FILE *fd1 ;                           
  FILE *fd2 ;
  FILE *fd  ; 

 
  char HOUT[30];
  char HIN[30];
  char LANX[30];
  char data[30];
  static const long max_read = 20 + 1;           
  char buffer[max_read + 1];                       
  char *last_newline;
  char *last_line;
  char *word ; 
  char *pch ; 





  if(argc == 4)
  {
    switch(i)
       {


         case 1:
          host1=atoi(argv[1]);  
          printf(" The Host ID is %d\n",host1);  
          i++;
  
         case 2:
          lan1=atoi(argv[2]);
          printf("The LAN ID is %d\n",lan1); 
          
          sprintf(LANX,"LAN%d.txt",lan1);                  

                 fd = fopen(LANX,"host1+");

                    if(NULL == fd)
                      {
                     printf("Cannot Open LAN FIle\n");
                     return 1;
                       }

                      else
                
                     {                                            
                       
                             
                       printf("Success opening LAN File");  

        
                         fclose(fd);  
                      }
            i++;

         case 3:
              strcpy(type,argv[3]);

                if ((strcmp(type,"receiver")) == 0)
                 { 


               sprintf(HOUT,"HOUT%d.txt",host1);
               sprintf(HIN,"HIN%d.txt",host1); 

               printf("Host type is %s\n",type);



       int startrec()
           {  
               fd1 = fopen(HOUT,"host1+");
               fd2 = fopen(HIN,"host1+"); 
         
               if(NULL == fd1)
                {
                   printf("Cannor Open File\n");
                   return 1;
                }

                else
                { 
                    printf("HOUT%d opened successfully\n",host1);
                  
                }
                if(NULL == fd2)
                {
                  printf("\n Cannot Open File\n");
                  return 1;
                }


                 else
                 { 
                   printf("HIN%d opened successfully\n",host1);

       
                 sprintf(LANX,"LAN%d.txt",lan1);                  

                 fd = fopen(LANX,"a+");

                    if(NULL == fd)
                      {
                     printf("Cannot Open LAN File\n");
                     return 0;
                       }

                      else
                
                     {                                            
                       
                             
                       printf("Success Opening LAN file");  

                   

                        fseek(fd, -max_read, SEEK_END);   
 

                        fread(buffer, max_read-1, 1, fd);

                        buffer[max_read-1] = '\0';                   

                        last_newline = strrchr(buffer, '\n');      
    
                        last_line = last_newline+1;              

                        word="data";

                        pch = strstr(buffer,word);
                    
                     printf("\nin bufferer : %s\n",buffer);
                     printf("in last_line:%s\n",last_line);  
   
                       if(pch)
                         {
                             printf("captured: [%s]\n", buffer);    
                             fputs("\n",fd2);
                             fputs(last_line,fd2);
                             
                               
                          }
                
       
                       if (count == 10)
                         {
                         fputs("\n",fd1);
                         sprintf(data,"receiver %d",lan1);
                         fputs(data,fd1);
                         count = 0;
                         
                         }
                       
                       fclose(fd);                               
                       fclose(fd1);
                       fclose(fd2); 

                       count = count + 1; 
                   }
            
                           loop_val = 100;
                  
                           if (k < loop_val)
                            {
                  
                                k++;

                             }}

                           for(; k < loop_val ; k++)
                           {
                              printf("Loop Value:%d\n",loop_val);
                              printf("Counter Value %s is:%d\n",type,k); 
                              sleep(1);
                              startrec();
                
                           }
 
                      }
                            
              
             
                 
              }
            i++;
           

         }
   
   }

  else              
  {

     switch(i)
      {

         case 1:
          host1=atoi(argv[1]);  
          printf(" The Host ID is %d\n",host1);  
          i++;
  
         case 2:
          lan1=atoi(argv[2]);
          printf("The LAN ID is %d\n",lan1); 
            i++;

         case 3:
              strcpy(type,argv[3]);

               i++;
    
         case 4:
               start_time = atoi(argv[4]);
                printf("Start time is %d\n",start_time);
                i++;

         case 5:
                 period = atoi(argv[5]);
                printf("Time period is %d\n",period);
                i++;
    
         }

        
        sleep(start_time);



              printf("The Host type is a %s\n",type);

              sprintf(HOUT,"HOUT%d.txt",host1);
   

     int startover()
             {
              fd1 = fopen(HOUT,"host1+");

              if(NULL == fd1)
                {
                  printf("\n Cannot Open File\n");
                  return 1;
                }
                else
                { 
               
                  printf("Hout%d file open suceesfull\n",host1);
                  sprintf(data,"data %d %d",lan1,lan1);
                  fputs("\n",fd1);
                  fputs(data,fd1);
                  fclose(fd1);
                  


                    if (loop_val == 0)
                     {
                     trem = 100 - start_time;
  
                     loop_val = trem / period;

                     }

               
                   if (k < loop_val)
                    {
                  
                      k++;

                     }
}
                   for(; k < loop_val ; k++)
                   {
                     printf("Loop Value is:%d\n",loop_val);
                     printf("COunter Value for host %s is:%d\n",type,k); 
                     sleep(period);
                     startover();
                
                   }


                }
                  
               
            }
 
              
           
           return 0; 
   }




 


