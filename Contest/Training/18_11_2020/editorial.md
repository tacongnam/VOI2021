# LRXOR + XOR
Trie

# XOR3
Chú ý: $\oplus$ = xor

Subtask 1:

Ta sẽ cố định được giá trị $y$, $z$ => Cần tìm giá trị $x \in [A_1, B_1]$ sao cho $x \oplus y \oplus z$ là lớn nhất (nhỏ nhất)

Gọi $w = x \oplus y$. Để giá trị trên là lớn nhất thì nếu bit tương ứng của $w$ là $b$ thì bit tương ứng của $z$ là $1 - b$. Chú ý có thêm biến $tight$ để kiểm tra xem có vượt quá $B_1$ hoặc vượt dưới $A_1$ hay không. Nên sử dụng đệ quy để viết cho dễ

```
void get_max(int pos, bool tightA, bool tightB, int val, int A, int B) {
	if(pos == -1) {
		res = max(ans, res);
		return ;
	}
	int b = bit(val, pos);
	int bitA = bit(A, pos);
	int bitB = bit(B, pos);
	int choose = 1 - b;

	if(tightA == true && choose < bitA)
		choose = 1 - choose;
	if(tightB == true && choose > bitB)
		choose = 1 - choose;

	bool ntA = (choose == bitA) ? tightA : false;
	bool ntB = (choose == bitB) ? tightB : false;
	ans += mask(pos) * (choose ^ b);
	get_max(pos - 1, ntA, ntB, val, A, B);
	ans -= mask(pos) * (choose ^ b);
}
```
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTEzNDg1NDE5OCwxNjMwMzQ3NzE0LDEzOT
c5NzI4MDQsMTE5NTEzNDAxMSwxOTE3NzAzMTgwXX0=
-->