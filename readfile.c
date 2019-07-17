#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char *line;
    char buffer[1024];
    char * record;
    char filename[] = "04.csv";
    if((fp = fopen(filename, "r")) != NULL) {
        fseek(fp, 1L, SEEK_SET);
        char delims[] = ",";
        int size_data = 0;
        
        
        while((line = fgets(buffer, sizeof(buffer), fp)) != NULL){
            if(line == NULL){
                return 0;
            }
            record = strtok(line, delims) ;
            while(record){
                record = strtok(NULL, delims);
                //atoi(record);
                size_data ++;
            }
        }

        float *data = (float *)malloc(size_data  * sizeof(float));
        int i =0;
        fseek(fp, 1L, SEEK_SET);
        while((line = fgets(buffer, sizeof(buffer), fp)) != NULL){
            if(line == NULL){
                return 0;
            }
            record = strtok(line, delims) ;
            while(record && *record){
                if(i % 2==0 || i % 3 == 0 ){
                    data[i] =  atof(record);
                }
                record = strtok(NULL, delims);
                i++;
                if (i > size_data) {  break;}
                //atoi(record);
            }
        }

        for(int i = 0; i < size_data; i++){
            printf("hello, record: %f\n", data[i+2]);
        }
        free(data);
    }
    fclose(fp);
    return  0;

}
