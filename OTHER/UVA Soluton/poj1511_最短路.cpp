#include <stdio.h>
#include <string.h>

#define	MAXN 1000010

bool	Mk [MAXN];

int	N , M;
__int64	Bucket [MAXN] , Next [MAXN] , value [MAXN] , a [MAXN] , b [MAXN];
__int64	MinCost [MAXN] , HeapSize , Heap [MAXN] , Cd [MAXN];

void init ()
{
	memset ( Bucket , 0xff , sizeof ( Bucket ));
	scanf ( "%d%d" , &N , &M );
	for (int i = 0; i < M; i ++ ) {
        scanf ("%I64d%I64d%I64d" , &a [i] , &b [i] , &value [i] ) , a [i] -- , b [i] -- ;
        Next [i] = Bucket [a [i]]; Bucket [a [i]] = i;
	}
}

void fly ( int K )
{
	__int64	q = K , p = ( q - 1 ) >> 1 ,Pos = Heap [K]; 
	__int64 Key = MinCost [Heap [K]];
	while ( q ) {
		if ( MinCost [Heap [p]] <= Key ) break;
		Heap [q] = Heap [p] , Cd [Heap [q]] = q;
		q = p , p = ( q - 1 ) >> 1;
	}
	Heap [q] = Pos , Cd [Pos] = q;
}

void GoDown ()
{
	__int64	p = 0 , q = 1, Pos = Heap [0];
	__int64 Key = MinCost [Heap [0]];
	while ( q < HeapSize ) {
		if ( q + 1 < HeapSize && MinCost [Heap [q + 1]] < MinCost [Heap [q]] ) q ++;

		if ( MinCost [Heap [q]] >= Key ) break;
		Heap [p] = Heap [q] , Cd [Heap [q]] = p;
		p = q , q = ( p << 1 ) + 1;
	}
	Heap [p] = Pos , Cd [Pos] = p;
}

__int64	Answer ( __int64 Contact [] )
{
	__int64	Ret = 0;
	memset ( MinCost , 0xff , sizeof ( MinCost ));
	memset ( Mk , 0 , sizeof ( Mk ));
	memset ( Cd , 0xff , sizeof ( Cd ));

	HeapSize = 1 , Heap [0] = 0 , Cd [0] = 0;

	__int64	i , k;
	MinCost [0] = 0;
    while ( HeapSize ) {
		k = Heap [0];
		Mk [k] = true;
		Heap [0] = Heap [-- HeapSize];
		Cd [Heap [0]] = 0;
		GoDown ();

		for ( i = Bucket [k]; i != -1; i = Next [i] ) if ( !Mk [Contact [i]] )

		if ( MinCost [Contact [i]] == -1 || MinCost [k] + value [i] < MinCost [Contact [i]] ) {
			if ( MinCost [Contact [i]] == -1 ) Heap [HeapSize ++] = Contact [i] , Cd [Contact [i]] = HeapSize - 1;
			MinCost [Contact [i]] = MinCost [k] + value [i];
			fly ( Cd [Contact [i]] );
		}

	}
	for ( i = 0; i < N; i ++ ) Ret += MinCost [i];
	return  Ret;
}

void Change ()
{
    memset ( Bucket , 0xff , sizeof ( Bucket )); 
	for ( int i = 0; i < M; i ++ )
        Next [i] = Bucket [b [i]], Bucket [b [i]] = i;
}

int main()
{
    int Total;
	__int64 Ans;
    for ( scanf ( "%d" , &Total ); Total; Total -- ) {
		init ();
		Ans = Answer ( b );
		Change ();
		Ans += Answer ( a );
		printf ( "%I64d\n" , Ans );
	}
}
