
# A. Evacuation (J - ACM ICPC miền Bắc 2020)
Chặt nhị phân thời gian. Với mỗi thời gian t sử dụng luồng để kiểm tra có tồn tại cách để chia mọi người vào các hầm trú hay không.

# B. Planes
> Nhận xét
>
>+) Nếu tạo đường được -> tạo luôn
>
>+) Nếu tạo đường mà cần phải dùng cung ngược -> chắc chắn những đỉnh đã tạo trước nó phải tìm được một đường khác để tạo đường (giống giống cặp ghép)

-> Tạo trước mạng với những người tham gia cuộc thi

-> Kiểm tra xem có thể xếp hay không

-> Thêm vào mạng những người còn lại

-> Chạy thuật toán maxflow

+) Chú ý: Sau khi kiểm tra xem có kết quả hay không, ta không reset lại flow mà add tiếp cạnh rồi chạy tiếp maxflow

# C. Lamps

# D. Erase to max
Làm làm là ra

# E. Cash machine
Nhận xét:

Gọi $Count(b)$ = đáp án với $b_i = b$

$Count(b) = max(Count(b - 1), Count(b - f(b) + 1)$

Với $f(b) = max_{a_i}{3}$
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE1OTIxOTUyOSwxNDUzMzA1OTEwLDI5OD
M2MDU5NywtMzkzOTU4MTI4LC05NjQ4MDIxMzUsOTM1NDY3OTk5
LDEyNjIxNjgwODYsLTU5MTc0NTgwOCwxMDg1MjQ5MzY2LC05ND
U5NzUxMTksMTU5Njg3Njk0Nyw5MDkyOTE0MTcsMjk2Njk4OTI1
XX0=
-->