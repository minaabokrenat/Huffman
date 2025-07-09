#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
int * eq(char file[]){
    FILE * f;
    f=fopen(file,"r+t");
     char v;
     char t;
     
        int num=1;
        int place=0;
        int p=0;
        while(feof(f)!=1){
          fscanf(f,"%c",&v);
          place++;
        }
       place--;
        rewind(f);
        int * caract = (int*)malloc(place * sizeof(int));

        for(int i=0;i<place;i++){
            caract[i]=0;
        }
        for(int i=0;i<place;i++){
            fscanf(f,"%c",&v);
            rewind(f);
            for(int g=0;g<place;g++){
             fscanf(f,"%c",&t);
             if(t==v){
                caract[g]+=1;
                break;
             }
            }
            fseek(f,i+1,SEEK_SET);
        }

return caract;
}













int numLevels(int a[],int len){
    int levels=0;
    int num=0;
    for(int i=0;i<len;i++){
    if(a[i]!=0){
        num++;
    }
    }

    return num-1;

}





int *  min(int a[],int len){
    int leftmin=0;
    int rightmin=0;
    int leftmin2=0;
    int d;
    for( d=len-1;d>=0;d--){
      if(a[d]!=0){
      rightmin=d;
      break;
      }
    }
    int i;
      int * arr = (int*)malloc(2 * sizeof(int));
for( i=len-1;i>=0;i--){
    if(a[i]!=0){
      if(a[i]<a[rightmin]){
        rightmin=i;
      }
    }
}
int boolean=1;
int p=0;
for(int i=rightmin-1;i<len;i++){
  if(a[i]==0)
  p++;
}
int nu=len-(len-p);
if(nu==p)
boolean=0;


if(rightmin!=0||boolean!=0){
for(int r=rightmin-1;r>=0;r--){
      if(a[r]!=0 && r!=rightmin){
      leftmin=r;
      break;
      }
    }

for(int m=len;m>=0;m--){
  if(a[m]!=0 && m!=rightmin){
      if(a[m]<a[leftmin]){
        leftmin=m;
      }
    }  
}
}



 for(int r=len;r>=0;r--){
      if(a[r]!=0 && r!=rightmin){
      leftmin2=r;
      break;
      }
    }
for(int m=len;m>=0;m--){
  if(a[m]!=0 && m!=rightmin){
      if(a[m]<a[leftmin2]){
        leftmin2=m;
      }
    }  
}

if(leftmin==0)
leftmin=leftmin2;

if(a[leftmin]>a[leftmin2])
leftmin=leftmin2;

if(rightmin>leftmin){
arr[0]=leftmin;
arr[1]=rightmin;
}
if(rightmin<leftmin){
arr[0]=rightmin;
arr[1]=leftmin;  
}
return arr;
}






char * Reverse(char a [],int size){
    char * num=(char *)malloc(sizeof(char)*size);
    int v=0;
    int i=0;
   for(int i=size-1;i>=0;i--){
    num[v++]=a[i];
   }
    return num; 
}



void places(int * p,int * mi,int size){
  int min=mi[0];
  int max=mi[1];
 
   if(p[max]==0)
  p[max]=max;
   if(p[min]==0)
  p[min]=max;
  else{
  for(int i=0;i<size;i++){
  if(p[i]==min)
  p[i]=max;
  }
}
}


char **  bin(char * binary[],int arr[],int place[],int size){
 int left=arr[0];
 int right=arr[1];
 if(place[right]==0){
  int k=0;
  while(binary[right][k])
  k++;

 binary[right][k]='1';
 }
 else{
  for(int i=0;i<size;i++){
    if(place[i]==right){
      int j=0;
  while(binary[i][j])
  j++;
      binary[i][j]='1';
    }
  }
 }
 if(place[left]==0){
   int k2=0;
  while(binary[left][k2])
  k2++;
  binary[left][k2]='0';
 }
 else{
  for(int ii=0;ii<size;ii++){
    if(place[ii]==left){
          int j1=0;
  while(binary[ii][j1])
  j1++;
      binary[ii][j1]='0';
    }
  }
 }
 places(place,arr,size);
  return binary;
}






int numtime(int * arr,int s){
    int n=0;
    for(int i=0;i<s;i++){
        if(arr[i]!=0)
        n++;
    }
    return n-1;
}





void newarr(int * arr,int *mi){
int max =mi[1];
int min =mi[0];
int m=arr[max]+arr[min];
arr[max]=m;
arr[min]=0;
}


int size(char file []){
     FILE * f;
    f=fopen(file,"r+t");
     char v;
       int place=0;
        while(feof(f)!=1){
          fscanf(f,"%c",&v);
          place++;
        }
       place--;
       return place;
}

int sizeoffile(char file[]){
  FILE * f=fopen(file,"r+t");
  char c;
  char t;
  int n=0;
  char s;
  int i=0;
  while(t!='$'){
    fscanf(f,"%c",&c);
     if(c=='$'){
    fscanf(f,"%c",&t);
    if(t=='$')
    break;
    else{
      fseek(f,-1,SEEK_CUR);
    }
    }
    fscanf(f,"%d",&n);
    fscanf(f,"%c",&s);
    i++;
   
  }
  return i;
}


int realsize(int a[],int s){
int num=0;
for(int i=0;i<s;i++)
num+=a[i];
return num;
}

void sum(char fi[]){
FILE * f=fopen(fi,"r+t");
char c;
while(feof(f)!=1){
fscanf(f,"%c",&c);
printf("%c\n",c);
}
}


int main(int argc,char*argv[]){
    char * option=argv[1];
    char * fi=argv[2];
    if(strcmp(option,"-c")==0){
        FILE * f;
         f=fopen("f8.huf","wt");
         FILE * file=fopen(fi,"r+t");
          int * a =eq(fi);
          int s=size(fi);
           int lev=numLevels(a,s);
          char ** binary=(char**)malloc(s*sizeof(char*));
          for(int i=0;i<s;i++){
            binary[i]=(char *)malloc(lev*sizeof(char));
          }

          int * place = (int*)malloc(s * sizeof(int));
          for(int k=0;k<s;k++){
            place[k]=0;
        }

          int time=numtime(a,s);
         int * cop=(int *)malloc(sizeof(int)*s);
         for(int p=0;p<s;p++){
          cop[p]=a[p];
         }
         for(int i=0;i<time;i++){
            int * m=min(cop,s);
            newarr(cop,m);
          binary=bin(binary,m,place,s);
         }
         
        for(int i=0;i<s;i++){
      binary[i]=Reverse(binary[i],lev);
       }
          char * caract=(char *)malloc(s*sizeof(char));
          rewind(file);
          char z;
         for (int i=0;i<s;i++){
          fscanf(file,"%c",&z);
          caract[i]=z;
         }

         for(int i=0;i<s;i++){
          if(a[i]!=0){
          fprintf(f,"%c",caract[i]);
          fprintf(f," ");
          fprintf(f,"%d",a[i]);
          fprintf(f," ");
         }
         }

         fprintf(f,"$$");
          
         for(int i=0;i<s;i++){
          if(a[i]!=0){
            for(int w=0;w<lev;w++){
            fprintf(f,"%c",binary[i][w]);
         }
          }
         else{
          for(int z=0;z<i;z++){
            if(caract[z]==caract[i]){
              for(int y=0;y<lev;y++){
              fprintf(f,"%c",binary[z][y]);
              }
              break;
            }
          }
         }
         fprintf(f," ");
          }
         
         fclose(f);
    }
         




    if(strcmp(option,"-d")==0){
      FILE *  mo=fopen("file","wt");  
        FILE * fl=fopen(fi,"r+t");
        char carct;
        int num;
         char space;
         int s=sizeoffile(fi);
        int * n=(int *)malloc(s*sizeof(int));
        char * c=(char *)malloc(s*sizeof(char));
        int i=0;
         for(int y=0;y<s;y++){
          fscanf(fl,"%c ",&carct);
          if(c[y]!='$'){
            c[y]=carct;
          fscanf(fl,"%d",&n[y]);
          fscanf(fl,"%c",&space);
         }
         }

         int reals=realsize(n,s);
           char ** binary=(char**)malloc(reals*sizeof(char*));
          for(int i=0;i<reals;i++){
            binary[i]=(char *)malloc(s*sizeof(char));
          }
              
            
            fscanf(fl,"%c",&carct);
            fscanf(fl,"%c",&carct);
            int p=0;
            int t=0;
            while(feof(fl)!=1){
              fscanf(fl,"%c",&carct);
              if(carct=='0'||carct=='1'){
              binary[t][p]=carct;
              p++;
              }
              if(carct==' '){
              t++;
              p=0;
              }
            }

            char * ca=(char *)malloc(sizeof(char)*reals);
            for(int r=0;r<s;r++){
              char x=c[r];
              int b=n[r];
              int y=0;
              while(ca[y])
                y++;
                ca[y]=x;
                char * m=binary[y];
             for(int i=y+1;i<reals;i++){
                if(strcmp(binary[i],m)==0){
                  ca[i]=x;
                }
             }
            }


           for(int g=0;g<reals;g++){
            printf("%c",ca[g]);
           }
           
         

         


        
    }
   

 }



