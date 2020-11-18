# LRXOR + XOR
Just just Trie

### Bài toán 2 (XOR3 subtask 2)
Cho đoạn [L, R] tìm x thuộc [L, R] sao cho x ^ a[i] là lớn nhất.

# XOR3

### Bài toán 2:
Cho x thuộc [A, B], y thuộc [C, D]. Tính toàn bộ x^y (các phép tính kết quả giống nhau thì chỉ tính 1 lần) rồi sắp xếp lại tăng dần. Tìm kết quả lớn thứ k.

# GIFT

### GIFT2: 
Tách N thành tổng của 3 số a, b, c sao cho 0 < a < b < c và S(a) + S(b) + S( c ) là nhỏ nhất với S(i) là tổng các chữ số của i
```
int tinh(i, nho, ok1, ok2, ok3) {
	if(i > k) {
		if(ok1 & ok2 & ok3 & !nho) return 0;
		else return -inf;
	}
	
	int best = -inf;
	for(ai: 0 -> 9) {
		if(ok2) min2 = 0;
		else min2 = ai;
		for(int bi: min2 -> 9) {
			if(ok3) min3 = 0;
			else min3 = bi;
			for(int ci: min3 -> 9)
				for(int nho2: 0 -> 2)
					if((ai + bi + ci + nho2) / 10 == nho && (ai + bi + ci + nho2) % 10 == ni) {
						tmp = (ai + bi + ci + nho) % 10 + tinh(i + 1, nho2, ok1 | (ai > 0), ok2 | (bi > ai), ok3 | (ci > bi));
						if(tmp > best) best = tmp;
					}
		}
	}
}
```

# ASTR
f(i, j) -> f(i + 1, j + 1) hoặc f(i + 1, j')

Xét duyệt ma trận:
```
for
```
<!--stackedit_data:
eyJoaXN0b3J5IjpbMzYyOTA0NjQzLC0xNDk3NDczMjgzLDE4MD
U4OTA3NTAsMjI0Mzc0Nzk3LDEyMDgwNDgyOCw4MTY1Mzc2MDUs
LTM0MTM2NjQ4MywtNTMxMzY1NjgzLDE3MTc1NDAwOTMsMzU4Mj
M3MTk3LC0xNDI4MjQ2NjQwLDExMzQ4NTQxOTgsMTYzMDM0Nzcx
NCwxMzk3OTcyODA0LDExOTUxMzQwMTEsMTkxNzcwMzE4MF19
-->