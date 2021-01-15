#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define ll long long  
ll arr[100001];
int N;
ll bigger(ll a, ll b) {
	if (a >= b) return a;
	else return b;
}
ll smaller(ll a, ll b) {
	if (a >= b) return b;
	else return a;
}
ll getMax(int start, int end) {
	ll max2 = 0;
	if (start == end) return arr[start] *arr[ start];
	if (start + 1 == end) {
		max2 = bigger(getMax(start, start), getMax(end, end));
		max2 = bigger(max2, (arr[start] + arr[end]) * smaller(arr[start], arr[end]));
		return max2;
	}
	int mid = (start + end) / 2;

	ll max = bigger(getMax(start, mid), getMax(mid, end));
	int leftP = mid - 1, rightP = mid + 1;
	ll min = arr[mid], sum = arr[mid];
	ll sumL, sumR,minL,minR;
	max = bigger(max, arr[mid] * arr[mid]);
	while (leftP >= start || rightP <= end) {
		if (leftP < start) { //right로.
			sum += arr[rightP];
			min = smaller(min, arr[rightP]);
			max = bigger(max, sum * min);
			rightP++;
		}
		else if (rightP > end) {
			sum += arr[leftP];
			min = smaller(min, arr[leftP]);
			max = bigger(max, sum * min);
			leftP--;
		}
		else {
			sumL = sum + arr[leftP];
			sumR = sum + arr[rightP];
			minL = smaller(min, arr[leftP]);
			minR = smaller(min, arr[rightP]);
			if (sumL * minL > sumR * minR) {
				sum += arr[leftP];
				min = smaller(min, arr[leftP]);
				max = bigger(max, sum * min);
				leftP--;
			}
			else {
				sum += arr[rightP];
				min = smaller(min, arr[rightP]);
				max = bigger(max, sum * min);
				rightP++;
			}
		}
	}
	return max;
}

int main(void)

{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%lld", arr + i);
	printf("%lld", getMax(0, N - 1));

	return 0;
}


