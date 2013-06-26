//F[i] = min ( F[k] + max(aj | k<j<=i)  | sum{aj | k<j<=i} <= M ) Ïß¶ÎÊ÷ÓÅ»¯ 
#include <cstdio>
#include <algorithm>
#define maxn 101000
using namespace std;
typedef long long int64;
const int64 Inf = 9999999999999999LL;

struct Node {
  int64 MinF, TotF;
  int MaxA;
  Node *Left, *Right;
  void Create(int, int);
  void Change_F(int, int, int);
  void Change_A(int, int, const int &);
  int64 Get_Value(int, int);
};

int MinP, MaxP, T, S;
int Pred [maxn], SS, Stack [maxn];
int n, A [maxn];
int64 sum [maxn], M, F [maxn];
int TreeSize;
Node ST [maxn * 2 + 2], *Root = ST;
void init();
void prepare();
void solve();

int main(){
  	init();
  	prepare();
  	solve();
}

void solve()
{
  	for(int i = 1; i <= n; i ++) if(A [i] > M) {
    	printf("-1\n");
    	return;
  	}
	memset(Pred, 0, sizeof(Pred));
  	SS = 0;
  	for(int i = n; i >= 1; i --) {
    	for(; SS && A [i] >= A [Stack [SS - 1]]; SS --) Pred [Stack [SS - 1]] = i;
    	Stack [SS ++] = i;
  	}
  	F [0] = 0, S = 0;
  	for(int i = 1; i <= n; i ++) {
    	for(T = i - 1; sum [i] - sum [S] > M; S ++);
    	Root->Change_F(MinP, MaxP, i - 1);
    	SS = S, S = Pred [i];
    	if(S <= T) Root->Change_A(MinP, MaxP, A [i]);
    	S = SS;
    	F [i] = Root->Get_Value(MinP, MaxP);
  	}
  	printf("%I64d\n", F[n]);
}

void prepare(){
  	MinP = 0, MaxP = n, TreeSize = 1, Root->Create(MinP, MaxP);
}

void init(){
	scanf("%d %I64d", &n, &M);
  	sum [0] = 0;
  	for(int i = 1; i <= n; i ++) scanf("%d", A + i), sum [i] = sum [i - 1] + A [i];
}

int64 Node::Get_Value(int l, int r){
  	if(MaxA != -1) TotF = MaxA + MinF;
  	if(S <= l && r <= T) return TotF;
  	if(r < S || T < l) return Inf;
  	int mid =(l + r) / 2;
  	if(MaxA != -1) Left->MaxA = Right->MaxA = MaxA;
  	return min(Left->Get_Value(l, mid), Right->Get_Value(mid + 1, r));
}

void Node::Change_A(int l, int r, const int & Value){
  	if(MaxA >= Value) return;
  	if(S <= l && r <= T) { MaxA = Value; TotF = MaxA + MinF; return; }
  	if(r < S || T < l) return;
  	if(l == r) { MaxA >?= Value; TotF = MaxA + MinF; return; }
  	if(MaxA != -1) Left->MaxA = Right->MaxA = MaxA;
  	int mid =(l + r) / 2;
  	Left->Change_A(l, mid, Value), Right->Change_A(mid + 1, r, Value);
  	MaxA =(Left->MaxA == Right->MaxA ? Left->MaxA : -1);
  	if(MaxA != -1) TotF = MinF + MaxA;
  	else TotF = min(Left->TotF, Right->TotF);
}

void Node::Change_F(int l, int r, int p){
  	if(l == r) { MinF = F [p]; TotF = MinF + MaxA; return; }
  	int mid =(l + r) / 2;
  	if(MaxA != -1) Left->MaxA = Right->MaxA = MaxA;
  	if(p <= mid) Left->Change_F(l, mid, p);
  	else Right->Change_F(mid + 1, r, p);
  	MinF = min(Left->MinF, Right->MinF);
  	if(MaxA != -1) TotF = MinF + MaxA;
  	else TotF = min(Left->TotF, Right->TotF);
}

void Node::Create(int l, int r){
  	MinF = Inf, MaxA = -1, TotF = Inf;
  	if(l == r) { Left = Right = NULL; return; }
  	int mid =(l + r) / 2;
  	Left = Root + TreeSize ++, Right = Root + TreeSize ++;
  	Left->Create(l, mid), Right->Create(mid + 1, r);
}

