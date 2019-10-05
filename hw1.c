#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int paint[51][51];
int val[51][51];
int main(){
      char buf[128] = "";
      char temp[128] = "";
      int N = 0, M = 0, flag = 1;
      gets(buf,128);
      for(int i =0; i<strlen(buf);i++){
            // printf("%c\n", buf[i]);
            switch(buf[i]){
                  case ' ': case '\n': case '\r': flag = 1; break;
                  default:
                        if(flag == 1){
                              flag = 0;
                              paint[0][M] = buf[i] - '0';
                              M++;
                        }
                        else{
                              paint[0][M-1] = paint[0][M-1]*10 + buf[i] - '0';
                        }
            }
      }flag = 1;
      while(scanf("%s",buf)!=EOF){
            N++;
            // printf("%s ",buf);
            paint[N][0] = atoi(buf);
            for(int i =1; i<M + 1; i++){
                  scanf("%s",buf);
                  paint[N][i] = atoi(buf);
                  // printf("%s ", buf);
            }
            // printf("\n");
      }
      // printf("%d %d\n", M, N);
      FILE *fp = fopen("formula", "w");
      
      fprintf(fp,"(declare-fun f (Int) Int)\n");
      fprintf(fp,"(assert (= (f 0) 1))\n");
      fprintf(fp,"(assert (= (f 1) 0))\n");
      
      //declare p
      for(int i =1; i<= N;i++)
            for(int j = 0; j<M; j++)
                  fprintf(fp,"(declare-const p%d_%d Int)\n", i - 1, j);
      //range
      for(int i =1; i<= N;i++)
            for(int j = 0; j<M; j++)
                  fprintf(fp,"(assert (and (<= 0 p%d_%d) (<= p%d_%d 1)))\n",i-1,j,i-1,j);
      //black
      for(int i =0; i<M;i++){
            fprintf(fp,"(assert (= %d (+ ", paint[0][i]);
            for(int j = 1; j<=N;j++){
                  fprintf(fp,"(* %d p%d_%d) ",paint[j][i],j-1,i);
                  // printf("%d ",paint[j][i]);
            }
            // printf("\n");
            fprintf(fp,")))\n");
      }

      //white
      for(int i =1; i<=N;i++){
            fprintf(fp,"(assert (= %d (+ ", paint[i][M]);
            for(int j = 0; j<M;j++){
                  fprintf(fp,"(* %d (f p%d_%d)) ",paint[i][j],i-1,j);
            }
            fprintf(fp,")))\n");
      }

      fprintf(fp,"(check-sat)\n(get-model)\n");
      fclose(fp);

      FILE *out = popen("z3 formula","r");
      fscanf(out, "%s %s",buf,buf);
      int index = 0;
      while(!feof(out)){
            fscanf(out,"%s",buf);
            fscanf(out,"%s",buf);
            if(buf[0] == 'f') break;
            int num[2] = {0,0}, idx = 0;
            int len = strlen(buf);
            for(int i = 1; i < len; i++)
                  if(buf[i]=='_') idx++;
                  else num[idx] = num[idx]*10 + buf[i] - '0';
            fscanf(out,"%s",buf);
            fscanf(out,"%s",buf);
            fscanf(out,"%s",buf);
            val[num[0]][num[1]] = atoi(buf);
      }
      pclose(out);

      out = fopen("output","w");
      for(int i = 0; i< N;i++){
            for(int j =0;j<M;j++){
                  fprintf(out,"%d ",val[i][j]);
                  printf("%d ",val[i][j]);
            }
            fprintf(fp,"\n");printf("\n");
      }
      fclose(out);
      return 0; 
}