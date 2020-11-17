
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

# C. LAMP
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTU5ODY2MDE3LC05NjQ4MDIxMzUsOTM1ND
Y3OTk5LDEyNjIxNjgwODYsLTU5MTc0NTgwOCwxMDg1MjQ5MzY2
LC05NDU5NzUxMTksMTU5Njg3Njk0Nyw5MDkyOTE0MTcsMjk2Nj
k4OTI1XX0=
-->