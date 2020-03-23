#include <stdio.h>
#include <omp.h>
#include<limits.h>
#define N 15
int main()
{
    double arr1[N];
    omp_set_num_threads(5);
    double max_val = INT_MIN;
    double min_val = INT_MAX;
    int i;
    printf("Enter %d numbers \n",N);
    for( i=0; i<N; i++)
    {
        scanf("%lf",&arr1[i]);
    }
#pragma omp parallel for reduction(max : max_val)
    for( i=0;i<N; i++)
    {
        printf("thread id = %d and i = %d\n", omp_get_thread_num(), i);
        if(arr1[i] > max_val)
        {
            max_val = arr1[i];
        }
        if(arr1[i]<min_val)
        {
            min_val = arr1[i];
        }
    }
    printf("\nmax_val = %lf\n", max_val);
    printf("min_val = %lf\n", min_val);
}