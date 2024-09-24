#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int findCeil(int arr[], int r, int l, int h) 
{ 
    int mid; 
    while (l < h) 
    { 
         mid = l + ((h - l) >> 1);  // Same as mid = (l+h)/2 
        (r > arr[mid]) ? (l = mid + 1) : (h = mid); 
    } 
    return (arr[l] >= r) ? l : -1; 
} 

//a funcao do aleatorio, so colocar ela nos negocios da forma "gols(arr, freq, n)"
int gols(int arr[], int freq[], int n) 
{ 
    // Create and fill prefix array 
    int prefix[n], i; 
    prefix[0] = freq[0]; 
    for (i = 1; i < n; ++i) 
        prefix[i] = prefix[i - 1] + freq[i]; 

    // prefix[n-1] is sum of all frequencies. Generate a random number 
    // with value from 1 to this sum 
    int r = (rand() % prefix[n - 1]) + 1; 

    // Find index of ceiling of r in prefix array 
    int indexc = findCeil(prefix, r, 0, n - 1); 
    return arr[indexc]; 
} 


int main()
{
    int time1 = 0, time2 = 0;
    //valores que eu quero
    int arr[]  = {0, 1, 2, 3, 4, 5, 6, 7}; 
    //probabilidade de cada um
    int freq[] = {50, 70, 30, 20, 15, 10, 5, 1};
    //sla o que faz
    int i, n = sizeof(arr) / sizeof(arr[0]);
    time_t t;

   /*Numero aleatorio basico, utiliza-se com o rand */
   srand((unsigned) time(&t));
    //ou srand(time(NULL));

    //funcao com o nome modificado, a funcao "gols()" eh a do aleatorio
    time1 = gols(arr, freq, n);
    time2 = gols(arr, freq, n);


    //rando com um limite, comecando em 0
    //rand() % 2;

   
    return 0;
}
