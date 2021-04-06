/*
 * ------------------------------------------
 *      ������������ �ع� (�ǹ����ù�)      *
 * ------------------------------------------
 */

#include <stdio.h>
#include <math.h>

#define N 3     /* ���� �� */

int main(void)
{                                   /* ������ */
    static double a[N][N+1]={{2.0  ,3.0  ,1.0  ,4.0  },
                             {4.0  ,1.0  ,-3.0 ,-2.0 },
                             {-1.0 ,2.0  ,2.0  ,2.0  }};
    double p,d,max,dumy;
    int i,j,k,s;

    for (k=0;k<N;k++){
        max=0;s=k;
        for(j=k;j<N;j++){
            if (fabs(a[j][k])>max){
                max=fabs(a[j][k]);s=j;
            }       
        }       
        if (max==0){
            printf("Ǯ �� ����");
            exit(1);
        }       
        for (j=0;j<=N;j++){
            dumy=a[k][j];
            a[k][j]=a[s][j];
            a[s][j]=dumy;
        }       

        p=a[k][k];              /* �ǹ� ��� */
        for (j=k;j<N+1;j++)        /* �ǹ����� p�� ���� */
            a[k][j]=a[k][j]/p;
        for (i=0;i<N;i++){      /* �ǹ��� �Ұ� */
            if (i!=k){ 
                d=a[i][k];
                for (j=k;j<N+1;j++)
                    a[i][j]=a[i][j]-d*a[k][j];
            }
        }
    }

    for (k=0;k<N;k++)
        printf("x%d=%f\n",k+1,a[k][N]);

	return 0;
}
