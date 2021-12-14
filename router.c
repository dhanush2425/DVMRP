#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>


int main(int argc , char **argv)
{



  int L[10];
  int router_id=0;
  int i,j,a,c,k=0;
  int loop_val = 0,B=0;
  int r=0,l=0;


  char *R0[24];


  char routing_table[10][3];
  int M[10][3]; 

  static const long max_len = 126 + 1;  
  char buffer[max_len + 1];               



  FILE *fd1 = NULL;
  FILE *fd2 = NULL;
  char dtm[150];
  FILE *fd3 = NULL;
 
  FILE *fd;  
  
  char *token = NULL;

  char dv[130],temp[20];
    
  char ROUTX[20];
  char LANX[20];

router_id = atoi(argv[1]);
printf ("The Router ID is : %d",router_id);
printf("Router is started\n");
for(i=0 ; i<10 ; i++)
    {
         routing_table[i][0]=i;
        routing_table[i][1]=10;
        routing_table[i][2]=router_id; 
  
        }


    sprintf(ROUTX,"ROUT%d.txt",router_id);
    if((fd1 = fopen(ROUTX,"a+")) == NULL)
        {
        printf("Cannot Open File %s\n",ROUTX);
        exit(1);
        }
               
        for (c=2; c < argc; c++)
                         {
                           
                           L[l]=atoi(argv[c]);
                          
                           routing_table[L[l]][1] = 0 ;
                           routing_table[L[l]][2] = router_id;
                           
                           printf("The LAN ID is %d\n",L[l]);

                           sprintf(LANX,"LAN%d.txt",L[l]);
                           printf("%s\n",LANX);  
                                        
                           if((fd = fopen(LANX,"a+")) == NULL)
                                 {
                                     printf("Cannot open File %s",LANX);
                                      continue;
                                  }
                                            
                                fclose(fd);
                           


                           sprintf(dv,"DV %d %d",L[l],router_id); 
                           l++;

                            for(i=0 ; i<10 ; i++)
                            {
                                M[i][0]=i;
                                M[i][1]=10;
                                M[i][2]=i; 
                                
                                if(l==i)  
                                 {
                                 M[i][1]=0;
                                 M[i][2]=router_id;
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
                    printf(" in router %d\n",router_id);
                    if(l != 0)
                       {
                          for(r=0; r < l ; r++) 
                           {
                             sprintf(LANX,"LAN%d.txt",L[r]);

                             if((fd = fopen(LANX,"r")) == NULL)
                              {
                                printf("Cannot open File %s",LANX);
                                  break;
                               }
                        
                

              
                  fseek(fd, -max_len, SEEK_END);      

                  fread(buffer, max_len-1, 1, fd);

                  fclose(fd);                                    
  
                 buffer[max_len-1] = '\0';                         

                char *last_newline = strrchr(buffer, '\n');       
    
                char *last_line = last_newline - 1;               


                char *word="DV";

                char *pch = strstr(buffer,word);
  

                      if(pch)
                         {
                            
                            printf("Found %s\n", buffer);    
        

                            strcpy(dtm, buffer);

                          }


                            if (strlen(dtm) != 0)
                             {
                               printf("\n The contents are \n");
 
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

         if (router_id != atoi(R0[2])) 
           {
                      
             for(i=0; i<10; i++) 
             {  
             
               if(routing_table[i][1] > (atoi(R0[k])))
                {
                
                 routing_table[i][1]=((atoi(R0[k])) + 1);
                 printf("%d",(R0[k+1][6] - '0'));
                 routing_table[i][2] = (R0[k+1][6] - '0');
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
               printf("%d\t",routing_table[i][j]); 
                }
                printf("\n"); 
             }
            }               
         }                
      }
}
                           loop_val = 100;
                  
                           if (B < loop_val)
                            {
                  
                                B++;

                             }

                           for(; B < loop_val ; B++)
                           {
                              printf("Loop Value is:%d\n",loop_val);
                              printf("Counter Value is:%d\n",B); 
                              sleep(1);
                              routerfunction();
                           }

           return 0; 
  }



       
                
      


   

