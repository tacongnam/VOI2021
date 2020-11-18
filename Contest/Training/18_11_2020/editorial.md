# LRXOR + XOR
Just just Trie

### Bài toán 2 (XOR3 subtask 2)
Cho đoạn [L, R] tìm x thuộc [L, R] sao cho x ^ a[i] là lớn nhất.

# XOR3

Subtask 1 + 2:

Ta sẽ cố định được giá trị y, z => Cần tìm giá trị x thuộc [A1, B1] sao cho x ^ y ^ z là lớn nhất (nhỏ nhất)

Gọi w = x ^ y. Để giá trị trên là lớn nhất thì nếu bit tương ứng của w là b thì bit tương ứng của z là 1 - b. Chú ý có thêm biến tight để kiểm tra xem có vượt quá B1 hoặc vượt dưới A1 hay không. Nên sử dụng đệ quy để viết cho dễ

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

Subtask 3:

<!--stackedit_data:
eyJoaXN0b3J5IjpbMzU1OTk2NTcsLTUzMTM2NTY4MywxNzE3NT
QwMDkzLDM1ODIzNzE5NywtMTQyODI0NjY0MCwxMTM0ODU0MTk4
LDE2MzAzNDc3MTQsMTM5Nzk3MjgwNCwxMTk1MTM0MDExLDE5MT
c3MDMxODBdfQ==
-->