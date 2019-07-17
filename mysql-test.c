#include <stdio.h>
#include <stdarg.h>
#include <memory.h>
#include <mysql.h>
#include <stdlib.h>
#include <string.h>
#include <malloc/malloc.h>

#define  MAX_MEM 100000000
#define HOST "rnd.mixiot.top"
#define USER "root"
#define PASSW0RD "root123"
#define DB  "aplec"
#define PORT 3306

static MYSQL mysql, *sockt;
char sql[1024];
MYSQL_RES * res_ptr = NULL;

MYSQL_RES * data_res = NULL;
MYSQL_ROW row;
int num_fields;
int num_rows = 0;

void connect_mysql()
{
    memset(sql, 0x00, sizeof(sql));
    printf("runherer\n");
    mysql_init(&mysql);
    if(!(sockt = mysql_real_connect(&mysql, (char *)HOST, (char*)USER, (char*)PASSW0RD,
                    (char*)DB, (unsigned int)PORT, NULL, 0))){
    
        printf("Coul'nt connect to DB \b\n %s\b\n", mysql_error(&mysql));
    }
}
int main()
{
    connect_mysql();
    printf("connect success !");
    int i = 0;
    float *num = NULL; 
    num = (float *)realloc(num, sizeof(float)*MAX_MEM);
    int res = mysql_query(&mysql, "SELECT * FROM aplec_quan;");
    if(res){
        fprintf(stderr, "SELECT ERROR with get num : %s\n", mysql_error(&mysql));

    }else{

        res_ptr = mysql_store_result(&mysql);
        if(res_ptr){
            while((row = mysql_fetch_row(res_ptr))){
                if(row[3] != NULL){
                    int n = strspn(row[3], "01234567890.");

                if(strlen(row[3]) != n || strlen(row[3]) == 0) {
                   // printf("row is ->>>%s", row[3]);
                }

                else{
                    //atof(row[3]);
                    *(num+i) = atof(row[3]);
                    i++;

                    //printf("num %f\n", num[j]);
                    }

              } }
          } 
          if(mysql_errno(&mysql)){
          fprintf(stderr, "Retrive errror: %s\n", mysql_error(&mysql));
                                                                          }
                      mysql_free_result(res_ptr);
                              }
            
    


       float * data = (float *)malloc(i * sizeof(float));
       for(int n=0; n < i; n++){
       
            data[n] = num[n];
       }

       free(num);
        //printf("size of malloc is t->>> %d\n", malloc_usable_size(num));
       printf("i is ->>>%d\n",i);
       float * result = (float *)malloc(MAX_MEM * sizeof(float));
       for(int ii =0; ii<i; ii++){
          if(ii == MAX_MEM) {
            break;
          }else{
          result[ii] = data[ii+1]-data[ii];
          
         printf("data is :%0.2f\n", result[ii]);
          }

        }
    
    free(data);
    free(result);
   mysql_close(&mysql);
                                                                                                                                                                                                                                                                                                                                                        }
       
