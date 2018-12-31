#include <iostream>
<<<<<<< HEAD
#define max 500
using namespace std;

int front=-1;
int rear=-1;
int readyQ[max];

int minAt(int AT[], int n) {
    int k, min = AT[0];
    int ind;
    for (k=0;k<n;k++) {
        if (AT[k] < min) {
            min = AT[k];
            ind = k;
            }
    }
    return ind;
}

void insert(int data) {

    if (front==-1) front=0;

    rear++;
    readyQ[rear] = data;
}

int main() {
    int n, tq;
    int t,i;
    cin >> n >> tq;

    int *AT = new int[n];
    int *BT = new int[n];
    int *P = new int[n];
    int *Flag = new int[n];
    int *inQ = new int[n];

    for (t=0;t<n;t++) {
        cin >> P[t] >> AT[t] >> BT[t];
        Flag[t] = 0;
        inQ[t] = 0;
    }
    int temp,temp1,temp2;
    
    for (t=0;t<n;t++) {
        for (i=t+1;i<n;i++) {
            if (AT[t] < AT[i]) {
                
                temp = AT[t];
                AT[t] = AT[i];
                AT[i] = temp;

                temp1 = BT[t];
                BT[t] = BT[i];
                BT[i] = temp1;

                temp2 = P[t];
                P[t] = P[i];
                P[i] = temp2;
            }
        }
    }
    int cur, ind;
    
    int btSum=0;
    for (t=0;t<n;t++) btSum += BT[t];

    int getin = minAt(AT,n);
    int track = AT[getin];

while (btSum > 0) {

    for (t=0;t<n;t++) {
        if (!Flag[t] && !inQ[t]) {
            if (AT[t] <= track) {
                insert(P[t]);
            }
        }
    }

    cur = readyQ[front]; 
    cout << cur;

    for (t=0;t<n;t++) {
        if (P[i] == cur) {
            ind = i;
            break;
            }
    }
    cout << ind << " ";

    if (BT[ind] > tq) {
        track += tq;
        btSum -= tq;
        BT[ind] -= tq;
        inQ[ind] = 1;
    }
    else {
        track += BT[ind];
        btSum -= BT[ind];
        BT[ind]=0;
        Flag[ind]=1;
        inQ[ind]=0;
    }

    
    for (t=0;t<n;t++) {
        if (!Flag[t] && !inQ[t]) {
            if (AT[t] <= track) {
                insert(P[t]);
                inQ[t] = 1;
            }
        }
    }

    if (BT[ind] > 0) {
        front++;
        insert(P[ind]);
        inQ[ind]=1;
    }
    else {  
        front++;
        inQ[ind]=0;
}
cout << track << " ";
}
=======
using namespace std;
int main()
{
    int wtime[10], btime[10], rtime[10], num, quantum, total;
    cout << "Enter number of processes(MAX 10): ";
    cin >> num;

    cout << "Enter burst time";
    for (int i = 0; i < num; i++)
    {
        cout << "\nP[" << i + 1 << "]: ";
        cin >> btime[i];
        rtime[i] = btime[i];
        wtime[i] = 0;
    }
    cout << "\n\nEnter quantum: ";
    cin >> quantum;
    int rp = num;
    int i = 0;
    int time = 0;
    cout << "0";
    wtime[0] = 0;
    while (rp != 0)
    {
        if (rtime[i] > quantum)
        {
            rtime[i] = rtime[i] - quantum;
            cout << " | P[" << i + 1 << "] | ";
            time += quantum;
            cout << time;
        }
        else
        {
            time += rtime[i];
            rtime[i] = rtime[i] - rtime[i];
            cout << " | P[" << i + 1 << "] | ";
            rp--;
            cout << time;
        }

        i++;
        if (i == num)
        {
            i = 0;
        }
    }
    system("pause");
    return 0;
>>>>>>> e12174f798d3f10d40067fef6800256ef6d5f321
}
