# Описание задачи
В файле input/variance_calc.tsv записаны значения некоторой выборки X. Необходимо посчитать скользящее среднее - x<sub>n</sub> и стандартное отклонение s<sub>n</sub> для первых n объектов этой выборки, а так же вывести x<sub>n</sub> и s<sub>n</sub> для n = 1, 100, 1000000, 500000000
## Решение
Стандартное вычисление x<sub>n</sub> и s<sub>n</sub> требует О(n) операций, но так как вычисление x<sub>n</sub> и s<sub>n</sub> происходит последовательно, мы можем пересчитать новые x<sub>n</sub> и s<sub>n</sub> при помощи предыдущих значений.

<img src="https://render.githubusercontent.com/render/math?math=x_n = \dfrac{x_{n-1} \+ (num_n - x_{n-1})}{n}">

<img src="https://render.githubusercontent.com/render/math?math=s_n = \sqrt{\dfrac{(n - 2) * s_{n-1}^{2} \+ (num_n - x_n) * (num_n - x_{n-1})}{(n - 1)}}">
