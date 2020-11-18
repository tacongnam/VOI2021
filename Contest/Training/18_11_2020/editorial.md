# LRXOR + XOR
Trie

# XOR3
Chú ý: $\oplus$ = xor

Subtask 1:

Ta sẽ cố định được giá trị $y$, $z$ => Cần tìm giá trị $x \in [A_1, B_1]$ sao cho $x \oplus y \oplus z$ là lớn nhất (nhỏ nhất)

Gọi $w = x \oplus y$. Để giá trị trên là lớn nhất thì nếu bit tương ứng của $w$ là $b$ thì bit tương ứng của $z$ là $1 - b$. Chú ý có thêm biến $tight$ để kiểm tra xem có vượt quá $B_1$ hoặc vượt dưới $A_1$ hay không.

```
int get_max(int x) {
	bool tightA = true, tightB = true;
	ford(i: 31 -> 0) {
		int b = bit(x, i);
		int bA = bit(A, i);
		int bB = bit(B, i);
		int choose = 1 - b;
		if(tightB == true) {
			if(choose > bB) 
		}
		if(tightA == true) {
			if(choose < bA)
				choose = 1 - choose;
			else if(choose > bA)
				tightA = false;
		}
	}
}
```
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTEyMDc4MjUwNTUsMTE5NTEzNDAxMSwxOT
E3NzAzMTgwXX0=
-->