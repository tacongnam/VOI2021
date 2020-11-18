# LRXOR + XOR
Trie

# XOR3
Chú ý: $\oplus$ = xor

Subtask 1 + 2:

Ta sẽ cố định được giá trị $y$, $z$ => Cần tìm giá trị $x \in [A_1, B_1]$ sao cho $x \oplus y \oplus z$ là lớn nhất (nhỏ nhất)

Gọi $w = x \oplus y$. Để giá trị trên là lớn nhất thì nếu bit tương ứng của $w$ là $b$ thì bit tương ứng của $z$ là $1 - b$. Chú ý có thêm biến $tight$ để kiểm tra xem có vượt quá $B_1$ ($A_1$ với nhỏ nhất) hay không.

```
int get_max(int x) {
	bool tight = true;
	ford(i: 31 -> 0) {
		int b = bit(x, i);
		if(1 - b
	}
}
```
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTE5NTEzNDAxMSwxOTE3NzAzMTgwXX0=
-->