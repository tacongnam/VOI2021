# Tổng quan kỳ thi
### Tên kỳ thi: CLC Offline Round 10
### Hình thức thi: Thi offline, chấm ngay sau giờ làm bài trên Codeforces
### Thời gian thi: 3h
### Đề thi có 6 trang, 4 bài

|Tên  bài                 |File chương trình | Input | Output | TL|Điểm|
|-------------------------------|-----------------------------|----|---|---|--| 
|Tìm số      | FINDNUM.CPP | FINDNUM.INP | FINDNUM.OUT | 1,5s |40
|Đoạn phủ |SEGCOVER.CPP|SEGCOVER.INP|SEGCOVER.OUT|1s|60
|Dãy số đẹp|GOODSEQ.CPP|GOODSEQ.INP|GOODSEQ.OUT|1s|60
|Dãy số| SEGFUNC.CPP | SEGFUNC.INP | SEGFUNC.OUT | 3s |40

### Thời gian thi: 10/1/2020

# A. Tìm số (FINDNUM - 40 điểm)

### **Memory limit: 1024MB  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;  Time limit: 1,5s**

Cho dãy $x$ có dạng: $x_n = nx_0 + (n-1)x_1 + (n-2)x_2 + ... + (n-i).x_i + ... + x_{n-1}$

Cho trước hai số $x_0 = a$, $x_1 = b$ và số $k$ $(a, b \leq 10^{9})$. Hãy in ra giá trị của $x_k$ lấy phần dư cho $998754457$.

### Input: Nhập từ file FINDNUM.INP

Dòng đầu tiên nhập một số nguyên $T$ – số test trong bài toán.

$T$ dòng sau, mỗi dòng chứa ba số nguyên $a$, $b$, $k$ – chi tiết của các truy vấn.

### Output: In ra file FINDNUM.OUT

In ra $T$ dòng, mỗi dòng là kết quả của bài toán.

### Scoring

Subtask 1 (15 điểm): $\sum{(k + 1)} \leq 20$.

Subtask 2 (25 điểm): $\sum{(k + 1)} \leq 10^6$.

### Example

|FINDNUM.INP                   |FINDNUM.OUT                        |
|-------------------------------|-----------------------------|
|3 <br> 2 3 2 <br> 2 3 3 <br> 2 3 4 | 7 <br>19 <br>50 |

> **Note**:  Ta có:
> $x_0 = 2$
> $x_1 = 3$
> $x_2 = 2x_0 + x_1 = 2.2 + 3 = 7$
> $x_3 = 3x_0 + 2x_1 + x_2 = 3.2 + 2.3 + 7 = 19$
> $x_4 = 4x_0 + 3x_1 + 2x_2 + x_3 = 4.2 + 3.3 + 2.7 + 19 = 50$

# B. Đoạn phủ (SEGCOVER – 60 điểm)

### **Memory limit: 1024MB  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;  Time limit: 1s**

Cho $n$ đoạn số, đoạn thứ $i$ phủ từ $x_i$ đến $y_i$ (bao gồm cả hai điểm $x_i$, $y_i$) trên trục số. Ta xếp chồng các đoạn này lên trục số thì nhận thấy các đoạn có thể rời nhau, tiếp xúc  nhau, hoặc cắt nhau.

Khi xem lại trục số, dựa trên vị trí phủ của các đoạn và vị trí cắt nhau giữa hai đoạn, ta thấy các đoạn ban đầu sẽ tách thành các đoạn mới nhỏ hơn. Xét đoạn $[u, v]$ có tính chất:

 - Tồn tại ít nhất một đoạn phủ trong $n$ đoạn phủ sao cho chúng bắt đầu tại $u$, kết thúc tại một điểm lớn hơn hoặc bằng $v$; hoặc bắt đầu tại một điểm nhỏ hơn hoặc bằng $u$, kết thúc tại $v$;
 
 - Không tồn tại đoạn phủ nào trong $n$ đoạn phủ sao cho chúng bắt đầu tại một điểm thuộc $(u, v)$; Không tồn tại đoạn phủ nào trong $n$ đoạn phủ sao cho chúng kết thúc tại một điểm thuộc $(u, v)$.

 -  Không tồn tại hai đoạn khác nhau $[a, b]$, $[u, v]$ sao cho $a \leq u < b \leq v$.

Gọi $c_u$ là số lượng đoạn ban đầu chứa đoạn mới thứ $u$. Gọi $k_1$, $k_2$, ..., $k_m$ là chỉ số các đoạn mới thuộc đoạn $[x_i, y_i]$ ban đầu. Ta định nghĩa $F_i$ là giá trị quan trọng của đoạn thứ $i$ ban đầu. Khi đó:  $F_i = \sum_{1}^m{c_{k_i}}$.

Xét ví dụ $n = 3$ và các đoạn phủ ban đầu có toạ độ: $[2, 5]$, $[1, 3]$, $[4, 7]$. Trục số khi đó sẽ được nhìn như sau:

![Trục số](https://i.ibb.co/zNJyTDv/trucso.png)

Ta thấy các đoạn trên cắt nhau và tạo ra thành các đoạn nhỏ hơn: $[1, 2]$, $[2, 3]$, $[3, 4]$, $[4, 5]$, $[5, 7]$. Khi đó giá trị $c_i$ của 5 đoạn trên lần lượt là ${1, 2, 1, 2, 1}$. Ta có thể tính được các giá trị $F$:

$F_1 = 2 + 1 + 2 = 5$.

$F_2 = 1 + 2 = 3$.

$F_3 = 2 + 1 = 3$.

### Input: Nhập từ file SEGCOVER.INP

Dòng đầu tiên chứa số nguyên $T$ – số bộ test $(T \leq 5)$

$T$ nhóm dòng tiếp theo có dạng:

Dòng đầu tiên chứa số nguyên $n$ - số lượng đoạn phủ.

$n$ dòng sau, dòng thứ $i$ gồm hai số nguyên $x_i$, $y_i$ $(1 \leq x_i< y_i \leq 10^9)$.

### Output: In ra file SEGCOVER.OUT

In ra $T$ dòng, mỗi dòng gồm $n$ số nguyên - giá trị của mảng $F$.

### Scoring

Subtask 1 (10 điểm): $n \leq 10^2$.

Subtask 2 (20 điểm): $n \leq 10^5$, $1 \leq x_i, y_i \leq 10^2$.

Subtask 3 (30 điểm): $n \leq 10^5$.

### Example

|SEGCOVER.INP                    |SEGCOVER.OUT                        |
|-------------------------------|-----------------------------|
|1<br>3<br>2 5<br>1 3<br>4 7<br> | 5 3 3|

# C. Dãy số đẹp (GOODSEQ– 60 điểm)

### **Memory limit: 1024MB  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;  Time limit: 1s**

Cho xâu $S$ gồm các chữ cái tiếng Anh in thường. Bạn cần phải đếm xem có bao nhiêu bộ $(i, j, u, v)$ với $1 \leq i \leq j < u \leq v \leq |s|$ sao cho xâu con liên tiếp $s[i...j]$ và $s[u...v]$ đều là hai xâu đối xứng.

Xâu con liếp $s[a...b]$ của một xâu $s$ là xâu bao gồm dãy các phần tử liên tiếp $s_as_{a+1}...s_b$.

Xâu $s$ được gọi là xâu đối xứng nếu ta viết xuôi hoặc viết ngược xâu đấy vẫn nhận được cùng một xâu. Ví dụ 'abacaba', 'abba', 'z' là xâu đối xứng.

### Input: Nhập từ file GOODSEQ.INP

Gồm một dòng chứa xâu $S$.

### Output: In ra file GOODSEQ.OUT

In ra một dòng là kết quả bài toán.

### Scoring

Subtask 1 (10 điểm): $1 \leq |s| \leq 30$

Subtask 2 (15 điểm): $1 \leq |s| \leq 80$

Subtask 3 (15 điểm): $1 \leq |s| \leq 200$.

Subtask 4 (20 điểm): $1 \leq |s| \leq 2000$.

### Example

|GOODSEQ.INP                    |GOODSEQ.OUT                        |
|-------------------------------|-----------------------------|
|aa|1|
|aaa|5|
|abacaba|36|

# D. Xây dựng dãy số (CONSARR - 40 điểm)

### **Memory limit: 1024MB  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;  Time limit: 3s**

Cho số $N$. Hãy đếm số dãy có độ dài $N$ sao cho không tồn tại ba phần tử liên tiếp có giá trị bằng nhau.

### Input: Nhập từ file CONSARR.INP

Dòng thứ nhất chứa số nguyên dương $T$ - số bộ test.

$T$ dòng sau, mỗi dòng chứa một số nguyên dương $N$.

### Output: In ra file CONSARR.OUT

In ra $T$ một dòng là kết quả bài toán lấy phần dư cho $10^9 + 7$.

### Scoring

Subtask 1 (6 điểm): $T \leq 10$, $n \leq 6$.

Subtask 2 (20 điểm): $T \leq 10$, $n \leq 10^5$.

Subtask 3 (14 điểm): $T \leq 10^5$, $n \leq 10^{18}$.


### Example

|CONSARR.INP                    |CONSARR.OUT         |
|-------------------------------|-----------------------------|
|2 <br>2 2<br>3 4<br>| 4 <br> 60|

<!--stackedit_data:
eyJoaXN0b3J5IjpbMTYxMjQxNDE5LDEwNTM0OTcwODAsLTEzND
QwMjU4OTYsNDEzMDgxNjcxLC0xMzQ0MDI1ODk2LDEwODYxMTA3
MDgsNjcwNTMzMjAzLDg3MDk5NTYxMyw2NzA1MzMyMDMsMTMxNz
M0NjgzLDU2OTQzMDU0MywxMjk3OTUzOTMzLDI3NTMyNDEzLC0z
NDg2Njg1ODEsMjEzMDk0NDA1MiwtNzcyNDQyODA4LDEwMzU1ND
E0MjIsLTE2NTA2NzIwNDgsLTUyNDExMjIxMSw2Njg5MjgwMzBd
fQ==
-->