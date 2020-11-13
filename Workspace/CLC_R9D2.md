
# Tổng quan kỳ thi
### Tên kỳ thi: CLC Offline Round 9 Day 2

|Tên  bài                 |File chương trình | Input | Output | TL
|-------------------------------|-----------------------------|----|---|---| 
|AND Graph      | AND.CPP | AND.INP | AND.OUT | 1s
|Trò chơi trên dãy |DIVGAME.CPP |DIVGAME.INP |DIVGAME.OUT| 1s
|Phát áo|TSHIRT.CPP|TSHIRT.INP|TSHIRT.OUT|2,5s

> Thí sinh nộp bài trên codeforces hoặc trên themis. 
> Link nộp bài trên CF: https://codeforces.com/group/6XjY6ruJpc/contests

<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
# A. **AND Graph (AND – 70 điểm)**
### **Memory limit: 1024MB  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;  Time limit: 1s**

Cho một đồ thị gồm $N$ đỉnh, đỉnh thứ $i$ được gán nhãn $A_i$ . Hai đỉnh $i$ và $j$ có cạnh nối đến nhau khi và chỉ khi ($A_i \& A_j$) $> 0$ ("$\&$" là phép AND, một phép toán tử trên bit). Thực hiện $Q$ truy vấn thuộc một trong hai loại: 

- Thay đổi nhãn của một đỉnh; 
- Đếm số thành phần liên thông của đồ thị. Các số $A_i$ trước và sau mỗi truy vấn đều nằm trong đoạn $[0; 10^9]$.

### Input: Nhập từ file AND.INP
Dòng đầu chứa số nguyên dương $N$, là số đỉnh của đồ thị ($1 \leq N \leq 100000$); 

Dòng thứ hai chứa $N$ số nguyên không âm $A_1$ , $A_2$ , …, $A_N$ , là nhãn ban đầu của các đỉnh ($0 \leq A_i \leq 10^9$); 

Dòng thứ ba chứa số nguyên dương $Q$ -số truy vấn cần thực hiện ($1 \leq Q \leq 100000$); 

$Q$ dòng tiếp theo, mỗi dòng có một trong hai dạng: 
- "! x y": Thay đổi nhãn của đỉnh $x$ thành $y$, nói cách khác, gán $A_x = y$ ($1 \leq x \leq N$, $0 \leq y \leq 10^9$); 
- "?": In ra số thành phần liên thông của đồ thị hiện tại.

### Output: In ra file AND.OUT
Với mỗi truy vấn dạng "?", in ra một dòng chứa số nguyên là số thành phần liên thông của đồ thị tại thời điểm được hỏi.
### Scoring
Subtask 1 (28 số điểm): $N$, $Q \leq	300$; 

Subtask 2 (42 số điểm): Không có ràng buộc gì thêm.

### Example

|AND.INP                   |AND.OUT                        |
|-------------------------------|-----------------------------|
|5<br>1 2 3 4 5<br> 5<br> ?<br> ! 5 8<br> ?<br> ! 2 6<br> ? | 1<br>3<br>2

<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>

# B. Trò chơi trên dãy (DIVGAME– 70 điểm)

### **Memory limit: 1024MB  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;  Time limit: 1s**

Sau những giờ học căng thẳng, Cường quyết định rủ Huy đến nhà mình chơi một trò chơi. Cách chơi của trò chơi này như sau: Cho dãy $A$ gồm $N$ số nguyên dương $a_1$, $a_2$, ..., $a_N$.  Cường cho trước một số nguyên dương $M$. Huy cần phải chia các dãy này thành các đoạn nhỏ hơn, mỗi đoạn gồm các phần tử liên tiếp sao cho: Tổng của mỗi đoạn đều nhỏ hơn hoặc bằng $M$. Với mỗi đoạn mà Huy chia, Cường sẽ nhận được số điểm bằng với giá trị phần tử lớn nhất trong đoạn đó. 

Do Huy muốn chiến thắng nên hãy tìm cách chia để tổng số điểm của Cường đạt được là nhỏ nhất.

### Input: Nhập từ file DIVGAME.INP

Dòng đầu tiên chứa số nguyên $T$ – số lượng test ($T \leq 10$).

$T$ nhóm dòng sau, mỗi nhóm có dạng:

Dòng thứ nhất chứa hai số nguyên dương $N$, $M$.

Dòng thứ hai chứa $N$ số nguyên dương $a_1$, $a_2$, ..., $a_N$ ($a_i \leq 10^9$)

### Output: In ra file DIVGAME.OUT

In ra $T$ dòng, dòng thứ $i$ là kết quả của test thứ $i$.

### Scoring

Subtask 1 (20 điểm): $n \leq 10^3$.

Subtask 2 (20 điểm): $n \leq 10^5$, $m \leq 100$.

Subtask 3 (30 điểm): Không giới hạn gì thêm.

### Example

|DIVGAME.INP                    |DIVGAME.OUT                        |
|-------------------------------|-----------------------------|
|1<br>8 17<br>2 2 2 8 1 8 2 1 | 12


> **Note**:  Trong test 1, Huy sẽ chia dãy thành 3 dãy con: 2 2 2, 8 1 8, 2 1. Số điểm mà Cường nhận được là 2 + 8 + 2 = 12.

<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
# C. Phát áo (TSHIRT– 60 điểm)

### **Memory limit: 1024MB  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;  Time limit: 2,5s**

Để tăng doanh thu ngày độc thân 11/11, shop Kunnychan bắt đầu tung ra sale khuyến mãi có một không hai: Mua một trả tiền hai, mua hai trả tiền sáu. Shop có nhiều size áo khác nhau, nhưng chỉ có $m$ size, được đánh số từ $1$ đến  $m$, áp dụng khuyến mãi.

Không phụ lòng mình, chủ shop Kunnychan đã nhận được những đơn đặt hàng đầu tiên từ 0h00m00s đêm đó. Chỉ trong 1 phút, toàn bộ kho đã được bán hết một cách thần kỳ. Trong lúc đăng ký, có $n$ người may mắn đã nhấn thanh toán kịp. Do có mỗi người có một vóc dáng khác nhau nên đôi khi muốn mua nhiều loại size áo khác nhau. Có bạn thích mặc áo nhỏ, có bạn thích mặc áo to. Có bạn muốn mua hai cái để tặng người yêu của mình. Tuy nhiên do chủ shop đang FA không chịu nổi cẩu lương nên quyết định mỗi người chỉ được phát đúng 1 áo duy nhất trong số các yêu cầu về size áo của mình. Mặt khác, shop cũng không thể bán quá nhiều áo trong mỗi size khiến cho ngày hôm sau bị sụt giảm doanh thu nên cũng có một vài điều kiện riêng được nêu ra dưới đây.

Cho biết yêu cầu của khách hàng. Viết một chương trình phân phát áo cho mỗi khách hàng, sao cho:

- Mỗi khách hàng chỉ nhận được một loại áo duy nhất, size áo này phải nằm trong yêu cầu chọn mua của khách hàng đó.

- Để tránh sụt giảm doanh thu vào ngày hôm sau, shop cần số lượng người mua size áo có nhiều người mua nhất phải là nhỏ nhất có thể (Xem thêm tại phần Note).

Hãy in ra số lượng người mua size áo có nhiều người mua nhất nhỏ nhất đó.

### Input: Nhập từ file TSHIRT.INP

Dòng đầu tiên nhập số  $t$  - số lượng test.

$t$  nhóm dòng sau có dạng:

- Dòng thứ nhất nhập hai số nguyên dương $n$,  $m$  - số lượng học sinh và số size áo ($n \leq 1000$, $m \leq 500$).
-  $n$  dòng tiếp theo, dòng thứ  $i$ có dạng: Tên của người thứ  $i$  \_dấu cách_ số lượng size áo có thể phát cho người thứ  $i$ \_dấu cách_ các size áo có thể phát cho người thứ  $i$. Dữ liệu đảm bảo không có hai người trùng tên.

Dữ liệu đảm bảo tổng yêu cầu của  $n$ người trong mỗi test nhỏ hơn $8000$.

### Output: In ra file TSHIRT.OUT

In ra $t$ dòng là kết quả của bài toán.

### Scoring

Subtask 1 (14 điểm): $T \leq 10$, $1 \leq N \leq 20$, $1 \leq a_i \leq 10^9$

Subtask 2 (28 điểm): $T \leq 5$, $1 \leq N \leq 5000$, $1 \leq a_i \leq 10^9$

Subtask 3 (28 điểm): $T \leq 3$, không có ràng buộc gì thêm về $N$, $a_i$.

### Example

|TSHIRT.INP                    |TSHIRT.OUT                        |
|-------------------------------|-----------------------------|
|2<br>3 2<br>John 2 1 2<br>Rose 1 2<br>Mary 1 2<br>5 4<br>A 3 2 3 4<br>L 2 1 2<br>O 3 1 3 4<br>N 2 1 3<br>E 2 1 3|2<br>2

> **Note**: 
Test 1: Phát John áo size 1, Rose, Mary áo size 2. Số lượng người mua size áo có nhiều người mua nhất là 2 (size 2).
Test 2: Phát cho L áo size 1, A, N áo size 2, E áo size 3, O áo size 4. Số lượng người mua size áo có nhiều người mua nhất là 2 (size 2).
