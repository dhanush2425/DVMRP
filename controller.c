#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>


int main(int argc , char *argv[])
{


  int i=1,j=1,k=0;
  int hout=1,rout=1,lout=1;
  int C=0;
  int loop_val=0,index = 0;
  int H[10],L[10];
  int h,r=0; 
  long size;
  
  
  char *R0[30];
  char host1[30] = "host";
  char router1[10] = "router";
  char lan1[10] = "lan";
  char *token = NULL;

  
  long R[10];
  char alpha[200];
  
  FILE *fd;    
  FILE *fd1;  
  FILE *fd2;

  static const long maxrouter_length = 116;  
  char buffrouter[maxrouter_length + 1] ;              

  static const long maxhost_length = 11;  
  char routerhost[maxhost_length + 1] ;              
  
  char LANX[20];
  char HOUTX[20];
  char ROUTX[20];
  



  
     

     k=argc;
     
     k=k-1; 
     
              
       if ((strcasecmp(host1,argv[i])) == 0)          
           
             {
             k=k-1;
              
             for (i=2; j == strlen(argv[i]);i++)
                       {
                          
                          H[hout]=atoi(argv[i]);
                          printf("The Host ID is %d\n",H[hout]);
                          hout = hout + 1; 
                          
                          k = k-1; 

                          if ( k==0 )
                            {
                              
                             break;

                             }                             
                       }
               }
             
                         
                       if((strcasecmp(router1,argv[i])) == 0)
                         {
                          
                          k=k-1;

                          for (i= i+1 ; j == strlen(argv[i]);i++)
                             {
                               R[rout]=atoi(argv[i]);  
                               printf(" The Router ID is %ld\n",R[rout]); 

                               rout = rout + 1 ;
                              
                               
                               k = k-1; 

                               
                               if ( k==0 )
                               {
                                  
                                 break;

                                }            
                             }
                          }
                    
                               if((strcasecmp(lan1,argv[i])) == 0)
                                 {
                                     
                                     k=k-1;
                                      
                                     for (i= i+1 ; j == strlen(argv[i]) ; i++)
                                        {
                                          L[lout]=atoi(argv[i]); 
                                          printf("The LAN ID is %d\n",L[lout]); 
                                          
                                          sprintf(LANX,"LAN%d.txt",L[lout]);
                                          printf("%s\n",LANX);  
                                        
                                         if((fd = fopen(LANX,"a+")) == NULL)
                                            {
                                             printf("Cannot open file %s",LANX);
                                             continue;
                                             }
                                            
                    
                                          
                                              fclose(fd);
               
                                        lout = lout + 1; 

                                        k = k-1; 

                                         if ( k==0 )
                                          {
                                            
                                            break;

                                          }            
                                         }
                                  }
            
           




            
        for(h=1; h < hout ; h++) 
              {
                sprintf(HOUTX,"HOUT%d.txt",H[h]);
                printf("%s\n",HOUTX);  

            if((fd1 = fopen(HOUTX,"a+")) == NULL)    
                     {
                       printf("Cannot open file %s",HOUTX);
                       break;
                     }

          
                    fclose(fd1);   
              }
 
 
         for(r=1; r < rout ; r++) 
              {
                
                sprintf(ROUTX,"ROUT%ld.txt",R[r]);
                printf("%s\n",ROUTX);  
                if((fd2 = fopen(ROUTX,"a+")) == NULL)
                    {
                      printf("Cannot open file %s",ROUTX);
                      continue;
                    }
                     
           
                  fclose(fd2);
             }


       int controllerfunction() 
          {
          
           if(hout != 0)
            {
            for(h=1; h < hout ; h++) 
              {
                sprintf(HOUTX,"HOUT%d.txt",H[h]);
                printf("%s\n",HOUTX);  

               if((fd1 = fopen(HOUTX,"r")) == NULL)
                     {
                       printf("Cannot open file %s",HOUTX);
                       break;
                     }

     

            
                 size = ftell(fd);
                 
                 fseek(fd1, -maxhost_length, SEEK_END);      

                 fread(routerhost, maxhost_length-1, 1, fd1);
           
               
                 fclose(fd1);                                   

                 routerhost[maxhost_length-1] = '\0';                         

                 char *last_newline = strrchr(buffrouter, '\n');        
    
                 char *last_line = last_newline + 1;               
 


                           strcpy(alpha, routerhost);

                 
                //            if ((atoi(R0[1])) > 0)
                  //         {
                              
 
                              sprintf(LANX,"LAN%d.txt",L[h]);

                             if((fd  = fopen(LANX,"a+")) == NULL)
                              {
                                printf("Cannot open file %s",LANX);
                                break;
                              }
                      
                        fputs("\n",fd);
                        fputs(routerhost,fd);
                        fclose(fd);
                       }
                     }
           
      //     }

     //    }


            if(rout != 0)                      
            {
   
           for(r=1; r < rout ; r++) 
              {
               
                sprintf(ROUTX,"ROUT%ld.txt",R[r]);
                printf("%s\n",ROUTX);  

                if((fd2 = fopen(ROUTX,"r")) == NULL)
                    {
                      printf("Cannot open file %s",ROUTX);
                      break;
                    }
             
           
                fseek(fd2, -maxrouter_length, SEEK_END);      

                fread(buffrouter, maxrouter_length-1, 1, fd2);

                fclose(fd2);                                    

                buffrouter[maxrouter_length-1] = '\0';                         

                char *last_newline = strrchr(buffrouter, '\n');       
    
                char *last_line = last_newline + 1;               

        
                
           
  //                if ( (atoi(R0[1])) > 0)
   //                   {
                          sprintf(LANX,"LAN%d.txt",L[r]);
                         if((fd  = fopen(LANX,"a+")) == NULL)
                         {
                           printf("Cannot open file %s",LANX);
                           break;
                          }
            
                   
                           fputs("\n",fd);
                           fputs(buffrouter,fd);
                           fclose(fd);
  
   //                     } 

               //      }
                  }
              }}
          
   
                           loop_val = 100;
                  
                           if (C < loop_val)
                            {
                  
                                C++;

                             }

                           for(; C < loop_val ; C++)
                           {
                              printf("loop_val Value :%d\n",loop_val);
                              printf("Time Counter:%d\n",C); 
                              sleep(1);
                              controllerfunction();
                           }

           return 0; 

 }




