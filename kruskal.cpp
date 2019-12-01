#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N, MEMO[100];
// N es el numero de nodos
vector<pair<int, pair<int, int>>> v;
// v es la lista de aristas

void agregaAlConjunto(int a, int b){MEMO[b] = a;}
int buscaNodo(int n)
{
    if (n == MEMO[n])
        return n;
    return (MEMO[n] = buscaNodo(MEMO[n]));
}

int Kruskall()
{
    int a; //Nodo A
    int b; //Nodo B
    int sum = 0; //suma de los pesos de las aristas

    // Odenamos las aristas de menor a mayor
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
        MEMO[i] = i;
    
    for (int i = 0; i < v.size(); i++)
    {
        // Del vector de aristas toma la aritas i y busca en nodo a
        a = buscaNodo(v[i].second.first);
        // Del vector de aristas toma la aritas i y busca en nodo b
        b = buscaNodo(v[i].second.second);
        if (a != b)
        {
            sum += (v[i].first);
            agregaAlConjunto(a, b);
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int  m, a, b, p;
    cin >> N >> m; // leemos nodos y aristas
    for (int i = 0; i < m; i++)
    {
        // Insertamos peso, nodo A, nodo B
        cin >> a >> b >> p;
        v.push_back(make_pair(p, make_pair(a, b)));        
    }
    cout <<"LONGITUD MINIMA >: "<< Kruskall() << endl;
    return 0;
}
