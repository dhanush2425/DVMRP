#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>


int main(int argc , char **argv)
{



  int L[10],myRID=0,i,j,a,c,k=0,loop = 0,B=0,r=0,l=0;


  char *R0[24];


  char RT[10][3];
  int M[10][3]; 

  static const long max_len = 126 + 1;  
  char buff[max_len + 1];               



  FILE *fd1 = NULL;
  FILE *fd2 = NULL;
  char dtm[150];
  FILE *fd3 = NULL;
 
  FILE *fd;  
  
  char *token = NULL;

  char dv[130],temp[20];
    
  char ROUTX[20];
  char LANX[20];



  if(argc > 10)
  {
   printf("Invalid Number of Arguments\n");
  }

     else
     {
                       myRID = atoi(argv[1]);
                       printf ("My Router-ID is : %d",myRID);

                     

      }
        
                      printf("Router is starting with following arguments:\n");

                        for(i=0 ; i<10 ; i++)
                            {
                                RT[i][0]=i;
                                RT[i][1]=10;
                                RT[i][2]=myRID; 
  
                             }


               sprintf(ROUTX,"ROUT%d.txt",myRID);

               if((fd1 = fopen(ROUTX,"a+")) == NULL)
                      {
                     printf("Error opening file %s\n",ROUTX);
                    exit(1);
                      }
               
              


                       

               
                         for (c=2; c < argc; c++)
                         {
                           
                           L[l]=atoi(argv[c]);
                          
                           RT[L[l]][1] = 0 ;
                           RT[L[l]][2] = myRID;
                           
                           printf("LAN-ID is %d\n",L[l]);

                           sprintf(LANX,"LAN%d.txt",L[l]);
                           printf("%s\n",LANX);  
                                        
                           if((fd = fopen(LANX,"a+")) == NULL)
                                 {
                                     printf("Error opening file %s",LANX);
                                      continue;
                                  }
                                            
                                fclose(fd);
                           


                           sprintf(dv,"DV %d %d",L[l],myRID); 
                           l++;

                            for(i=0 ; i<10 ; i++)
                            {
                                M[i][0]=i;
                                M[i][1]=10;
                                M[i][2]=i; 
                                
                                if(l==i)  
                                 {
                                 M[i][1]=0;
                                 M[i][2]=myRID;
                                 } 

                              sprintf(temp," %d router%d",M[i][1],M[i][2]); 
                              strcat(dv,temp);    
                            
                       
                            }       
   
                                   fputs("\n",fd1); 
                                   fputs(dv,fd1);
                              
                                                                    
                        }
                         


                        fclose(fd1);


     int routerfunction()
     {
                    printf(" in router %d\n",myRID);
                    if(l != 0)
                       {
                          for(r=0; r < l ; r++) 
                           {
                             sprintf(LANX,"LAN%d.txt",L[r]);

                             if((fd = fopen(LANX,"r")) == NULL)
                              {
                                printf("Error opening file %s",LANX);
                                  break;
                               }
                        
                

              
                  fseek(fd, -max_len, SEEK_END);      

                  fread(buff, max_len-1, 1, fd);

                  fclose(fd);                                    
  
                 buff[max_len-1] = '\0';                         

                char *last_newline = strrchr(buff, '\n');       
    
                char *last_line = last_newline - 1;               


                char *word="DV";

                char *pch = strstr(buff,word);
  

                      if(pch)
                         {
                            
                            printf("Found %s\n", buff);    
        

                            strcpy(dtm, buff);

                          }


                            if (strlen(dtm) != 0)
                             {
                               printf("\n The contents of the line as tokens is \n");
 
                               token = strtok(dtm," "); 

                            
                               while (token != NULL) 
                               {
                                 R0[k] = token; 
                                   k++;
                                 token = strtok(NULL," ");
                               
                               }
                               
                           

                          }

          if (pch)
          {
          k=3;

          printf("%d",atoi(R0[2]));

         if (myRID != atoi(R0[2])) 
           {
                      
             for(i=0; i<10; i++) 
             {  
             
               if(RT[i][1] > (atoi(R0[k])))
                {
                
                 RT[i][1]=((atoi(R0[k])) + 1);
                 printf("%d",(R0[k+1][6] - '0'));
                 RT[i][2] = (R0[k+1][6] - '0');
                }
               
                k= k+2;
              
            }
           }


        
           printf("\n");
           printf("\n");
           printf("The new routing table is:\n");

              for(i=0; i<10; i++) 
             {  
               for(j=0; j<3; j++) 
                {
               printf("%d\t",RT[i][j]); 
                }
                printf("\n"); 
             }
            }               
         }                
      }
}
                           loop = 100;
                  
                           if (B < loop)
                            {
                  
                                B++;

                             }

                           for(; B < loop ; B++)
                           {
                              printf("Value of loop is:%d\n",loop);
                              printf("Value of time counter in router is:%d\n",B); 
                              sleep(1);
                              routerfunction();
                           }

           return 0; 
  }



       
                
      


   
