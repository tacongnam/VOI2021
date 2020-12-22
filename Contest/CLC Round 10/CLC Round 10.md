# Tổng quan kỳ thi
### Tên kỳ thi: CLC Offline Round 10
### Hình thức thi: Thi offline, chấm ngay sau giờ làm bài trên Codeforces
### Thời gian thi: 3h

|Tên  bài                 |File chương trình | Input | Output | TL
|-------------------------------|-----------------------------|----|---|---| 
|Tìm số      | FINDNUM.CPP | FX.INP | FX.OUT | 1s
|Pizza               |PIZTOPP.CPP |PIZTOPP.INP |PIZTOPP.OUT| 2,5s
|LISCOPRIME|COPRIME.CPP|COPRIME.INP|COPRIME.OUT|1s

### Thời gian thi: 

# A. Tìm số (FINDNUM - 40 điểm)

### **Memory limit: 1024MB  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;  Time limit: 1s**

Cho dãy $x$ có dạng: $x_n = nx_0 + (n-1)x_1 + (n-2)x_2 + ... + (n-i).x_i + ... + x_{n-1}$

Cho trước hai số $x_1 = a$, $x_2 = b$ và số $k$. Hãy in ra giá trị của $x_k$.

### Input: Nhập từ file FINDNUM.INP

Dòng đầu tiên nhập một số nguyên $T$ – số test trong bài toán.

$T$ dòng sau, mỗi dòng chứa ba số nguyên $a$, $b$, $k$ – chi tiết của các truy vấn.

### Output: In ra file FINDNUM.OUT

In ra $T$ dòng, mỗi dòng là kết quả của bài toán.

### Scoring

Subtask 1 (15 điểm): $\sum{k} \leq 15$.

Subtask 2 (25 điểm): $\sum{k} \leq 10^6$.

### Example

|FINDNUM.INP                   |FINDNUM.OUT                        |
|-------------------------------|-----------------------------|
|2 <br> 2 3 3 <br> 2 3 4       | 7 <br>19 |

> **Note**:  Ta có:
> $f(1) = 2$
> $f(2) = 3$
> $f(3) = 2f(1) + f(2) = 2.2 + 3 = 7$
> $f(4) = 3f(1) + 2f(2) + f(3) = 3.2 + 2.3 + 7 = 19$

# B. Cặp số (PAIRTOP – 60 điểm)

### **Memory limit: 1024MB  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;  Time limit: 1s**

Cho hai dãy $A$ và $B$ gồm $N$ phần tử. Hãy tìm số lượng các cặp $(i, j)$ ($i < j$) sao cho $a_i + a_j > b_i + b_j$.

### Input: Nhập từ file PAIRTOP.INP
Dòng đầu tiên chứa số nguyên dương $N$ ($2 \leq N \leq 2.10^5$);

Dòng thứ hai chứa $N$ số nguyên dương $A_i$ ($A_i \leq 10^9$).

Dòng thứ ba chứa $N$ số nguyên dương $B_i$ ($B_i \leq 10^9$).

### Output: In ra file PAIRTOP.OUT

In ra một dòng là kết quả bài toán.

### Scoring

Subtask 1 (15 điểm): $1 \leq N \leq 1000$

Subtask 2 (15 điểm): $1 \leq a_i, b_i \leq 10^4$

Subtask 3 (30 điểm): Không có ràng buộc gì thêm.

### Example

|PAIRTOP.INP                    |PAIRTOP.OUT                        |
|-------------------------------|-----------------------------|
|5<br>4 8 2 6 2<br>4 5 4 1 3|7|
|4<br>1 3 2 4<br>1 3 2 4|0|

# C. Đoạn phủ (SEGCOVER – 60 điểm)

### **Memory limit: 1024MB  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;  Time limit: 1s**

Bài toán liên quan đến đoạn phủ rất nổi tiếng, ví dụ như bài tìm số đoạn ít nhất để phủ lên đoạn $[a, b]$ bất kỳ.  Nam cũng muốn nghĩ một bài đoạn phủ và anh ấy đã nghĩ ra một bài như sau:

Cho các đoạn số, đoạn thứ $i$ phủ trên đoạn $[x_i, y_i]$ trên trục số. Ta xếp chồng các đoạn này lên trục số thì nhận thấy các đoạn có thể rời nhau, cạnh nhau, hoặc cắt nhau.

Nếu hai đoạn cắt nhau thì chúng sẽ tách thành các đoạn mới nhỏ hơn. Gọi $c_u$ là số lượng đoạn ban đầu chứa đoạn mới thứ $u$. Gọi $k_1$, $k_2$, ..., $k_m$ là chỉ số các đoạn mới thuộc đoạn $[x_i, y_i]$ ban đầu. Ta định nghĩa $F_i$ là giá trị quan trọng của đoạn thứ $i$ ban đầu. Khi đó:  $F_i = \sum_{1}^m{c_{k_i}}$

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

$n$ dòng sau, dòng thứ $i$ gồm hai số nguyên $x_i$, $y_i$ $(1 \leq x_i, y_i \leq 10^9)$.

### Output: In ra file PIZTOPP.OUT

In ra $T$ dòng, mỗi dòng gồm $n$ số nguyên - giá trị của mảng $F$.

### Scoring

Subtask 1 (10 điểm): $n \leq 10^2$.

Subtask 2 (15 điểm): $n \leq 10^5$, $1 \leq x_i, y_i \leq 10^3$.

Subtask 3 (15 điểm): Không có điều kiện gì thêm.

### Example

|SEGCOVER.INP                    |SEGCOVER.OUT                        |
|-------------------------------|-----------------------------|
|1<br>3<br>2 5<br>1 3<br>4 7<br> | 5 3 3|

# D. Dãy số đẹp (GOODSEQ– 40 điểm)

### **Memory limit: 1024MB  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;  Time limit: 1s**

Cho xâu $S$ gồm các chữ cái tiếng Anh in thường. Bạn cần phải đếm xem có bao nhiêu bộ $(i, j, u, v)$ với $1 \leq i \leq j < u \leq v \leq |s|$ sao cho xâu con liên tiếp $s[i...j]$ và $s[u...v]$ đều là hai xâu đối xứng.

Xâu con liếp $s[a...b]$ của một xâu $s$ là xâu bao gồm dãy các phần tử liên tiếp $s_as_{a+1}...s_b$.

Xâu $s$ được gọi là xâu đối xứng nếu ta viết xuôi hoặc viết ngược xâu đấy vẫn nhận được cùng một xâu. Ví dụ 'abacaba', 'abba', 'z' là xâu đối xứng.

### Input: Nhập từ file GOODSEQ.INP

Gồm một dòng chứa xâu $s$.

### Output: In ra file GOODSEQ.OUT

In ra một dòng là kết quả bài toán.

### Scoring

Subtask 1 (5 điểm): $1 \leq |s| \leq 30$

Subtask 2 (10 điểm): $1 \leq |s| \leq 80$

Subtask 3 (10 điểm): $1 \leq |s| \leq 200$.

Subtask 4 (15 điểm): $1 \leq |s| \leq 2000$.

### Example

|GOODSEQ.INP                    |GOODSEQ.OUT                        |
|-------------------------------|-----------------------------|
|aa|1|
|aaa|5|
|abacaba|36|
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTgxMTg3OTk3NiwtMTY2NjE3MzYzNywzND
IyNDM5OTQsLTQ0ODIzMDE0MywtOTAwNDAyODY1LC0xMTM2NjQx
OTE0LC0yMDg4NzQ2NjEyXX0=
-->