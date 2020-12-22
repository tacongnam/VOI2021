# Tổng quan kỳ thi
### Tên kỳ thi: CLC Offline Round 10
### Hình thức thi: Thi offline, chấm ngay sau giờ làm bài trên Codeforces
### Thời gian thi: 3h

|Tên  bài                 |File chương trình | Input | Output | TL
|-------------------------------|-----------------------------|----|---|---| 
|Truy vấn      | FX.CPP | FX.INP | FX.OUT | 1s
|Pizza               |PIZTOPP.CPP |PIZTOPP.INP |PIZTOPP.OUT| 2,5s
|LISCOPRIME|COPRIME.CPP|COPRIME.INP|COPRIME.OUT|1s

### Thời gian thi: 

<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>

# A. 
### **Memory limit: 1024MB  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;  Time limit: 1s**

Xét hàm $F(x)$ có giá trị như sau:

+) $F(0) = 0$.

+) $F(1) = 1$.

+) $F(2) = 2$.

+) $F(x) = 0$ với $x$ là số nguyên tố lẻ.

+) $F(a.b) = F(a) + F(b)$ sao cho $a + b$ là nhỏ nhất.

Cho các truy vấn chứa số $x$, trả về giá trị của hàm $F(x)$.


### Input: Nhập từ file FX.INP

Dòng đầu tiên nhập một số nguyên $T$ – số test trong bài toán.

$T$ dòng sau, mỗi dòng chứa một số nguyên $x$ – truy vấn.

### Output: In ra file FX.OUT
In ra $T$ dòng, mỗi dòng là kết quả của bài toán.
### Scoring
Subtask 1 (15 điểm): $x \leq 100$.

Subtask 2 (15 điểm): $T = 1$, $x \leq 10^5$.

Subtask 3 (30 điểm): $T \leq 10^6$, $x \leq 10^{18}$.

### Example

|FX.INP                   |FX.OUT                        |
|-------------------------------|-----------------------------|
|1 <br> 4       | 4

> **Note**:  Ta có: $F(4) = F(2) + F(2) = 2 + 2 = 4$.

<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
# B. PIZZA (PIZTOPP – 70 điểm)

### **Memory limit: 1024MB  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;  Time limit: 2,5s**

Đội tuyển tin năm học 2020 – 2021 đang chuẩn bị một chiếc bánh Pizza siêu to khổng lồ để cả đội liên hoan trước khi thi. Cả đội tuyển có $n$ người và có tất cả $m$ loại topping cho chiếc bánh này. Chiếc bánh này có thể có nhiều loại topping khác nhau.

Mỗi người đều có sở thích ăn uống của riêng mình. Người thứ $i$ có hai  yêu cầu về sở thích của mình. Họ có thể thích hoặc không thích một món ăn nào đó. Hiệu muốn mua các loại topping sao cho thoả mãn cả $n$ người đó nhưng đôi khi có một vài xung đột (loại topping $i$ có thể có người thích, có người không thích) nên rất khó để mua. Tuy nhiên, do cũng là ngày trước khi thi nên anh ấy muốn thoả mãn ít nhất một nguyện vọng của mỗi người. Hãy lập một chương trình để giúp anh ấy đưa ra quyết định nên mua loại topping nào.

### Input: Nhập từ file PIZTOPP.INP

Dòng đầu tiên chứa số nguyên $T$ – thứ tự của subtask.

Dòng thứ hai chứa hai số nguyên $n$, $m$ – số lượng người và số loại topping sẵn có khác nhau.

$n$ dòng sau, mỗi dòng gồm $2$ số nguyên có dạng $x$  - miêu tả sở thích của người đó: $x < 0$ nếu người đó không thích loại topping $|x|$ hoặc $x > 0$ nếu người đó thích loại topping $x$ $(|x| \leq m)$. Đảm bảo $|x|$ của mỗi người đều phân biệt.

### Output: In ra file PIZTOPP.OUT

Dòng đầu tiên, in ra số nguyên $t$ – số loại topping mà Hiệu có thể mua.

Dòng thứ hai in ra $t$ số nguyên dương – chỉ số của $t$ loại topping mà Hiệu mua.

Nếu có nhiều đáp án, in ra một đáp án bất kỳ. Chú ý, một loại topping chỉ được mua một lần.

Nếu không tồn tại đáp án, in duy nhất một dòng $t$ = -1.

### Scoring

Subtask 1 (8,4 điểm): $n \leq 10^3$, $m \leq 15$.

Subtask 2 (22,4 điểm): $n \leq 15$, $m \leq 10^3$.

Subtask 3 (39,2 điểm): $n \leq 10^5$, $m \leq 10^6$.

### Example

|PIZTOPP.INP                    |PIZTOPP.OUT                        |
|-------------------------------|-----------------------------|
|1<br>3 5<br>1 2<br>-1 3<br>4 -2<br> | 4<br>1 2 3 4
|2<br>3 5<br>1 -2<br>-1 3<br>4 -2<br>| 3<br>1 3 4
|3<br>3 3<br>1 -2<br>-1 3<br>-3 -2<br>|2<br>1 3

> **Note**:  Trong test 1, Hiệu có thể mua cả 5 loại topping (1 2 3 4 5) hoặc chỉ mua 3 loại (1, 3, 4) đều được.

<br><br><br><br><br>
# C. LISCOPRIME (COPRIME – 70 điểm)

### **Memory limit: 1024MB  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;  Time limit: 1s**

Cho một dãy số nguyên $A$ gồm $N$ phần tử. Mọi phần tử $x$ trong $A$ đều có tính chất: nếu $x$ chia hết cho một số nguyên tố $p$ nào đó, thì $p$ phải bé hơn 12. Tìm một dãy con $B$ của dãy đã cho $A$ sao cho:

+) $B$ là dãy con của $A$ , tức là có thể thu được $B$ bằng cách xóa đi một số phần tử của $A$ (theo định nghĩa này, $A$ cũng là dãy con của $A$ , dãy rỗng cũng là dãy con của $A$);

+) $B$ là một dãy tăng, tức là phần tử đứng sau phải lớn hơn phần tử đứng trước (theo định nghĩa này, dãy gồm không hoặc một phần tử luôn là dãy tăng);

+) Hai phần tử liên tiếp của $B$ phải nguyên tố cùng nhau.

Hãy tìm ra dãy con $B$ có độ dài lớn nhất thỏa mãn các yêu cầu trên.

### Input: Nhập từ file COPRIME.INP
Dòng đầu tiên chứa số nguyên dương $N$ ($1 \leq N \leq 10^5$);

$N$ dòng tiếp theo, dòng thứ $i$ chứa số nguyên $a_i$ ($1 \leq a_i \leq 10^{18}$).

### Output: In ra file COPRIME.OUT

In ra độ dài lớn nhất của dãy con $B$.

### Scoring

Subtask 1 (14 điểm): $1 \leq N \leq 20$, $1 \leq a_i \leq 10^9$

Subtask 2 (28 điểm): $1 \leq N \leq 5000$, $1 \leq a_i \leq 10^9$

Subtask 3 (28 điểm): Không có ràng buộc gì thêm.

### Example

|COPRIME.INP                    |COPRIME.OUT                        |
|-------------------------------|-----------------------------|
|5<br>27<br>28<br>98<br>81<br>90 | 3
|3<br>9<br>27<br>81| 1

> **Note**: Giải thích ví dụ đầu tiên: Dãy ($27$, $28$, $81$) là một dãy con hợp lệ và có độ dài lớn nhất.số nguyên tố.

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTExMzY2NDE5MTQsLTIwODg3NDY2MTJdfQ
==
-->