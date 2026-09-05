# [level 3] 등굣길 - 42898 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42898) 

### 성능 요약

메모리: 4.72 MB, 시간: 0.05 ms

### 구분

코딩테스트 연습 > 동적계획법（Dynamic Programming）

### 채점결과

정확성: 50.0<br/>효율성: 50.0<br/>합계: 100.0 / 100.0

### 제출 일자

2026년 09월 06일 00:35:38

### 문제 설명

<p>계속되는 폭우로 일부 지역이 물에 잠겼습니다. 물에 잠기지 않은 지역을 통해 학교를 가려고 합니다. 집에서 학교까지 가는 길은 m x n 크기의 격자모양으로 나타낼 수 있습니다. </p>

<p>아래 그림은 m = 4, n = 3 인 경우입니다.</p>

<p><img src="https://asset.programmers.co.kr/files/ybm/056f54e618/f167a3bc-e140-4fa8-a8f8-326a99e0f567.png" title="" alt="image0.png"></p>

<p>가장 왼쪽 위, 즉 집이 있는 곳의 좌표는 (1, 1)로 나타내고 가장 오른쪽 아래, 즉 학교가 있는 곳의 좌표는 (m, n)으로 나타냅니다. </p>

<p>격자의 크기 m, n과 물이 잠긴 지역의 좌표를 담은 2차원 배열 puddles이 매개변수로 주어집니다. <strong>오른쪽과 아래쪽으로만 움직여</strong> 집에서 학교까지 갈 수 있는 최단경로의 개수를 1,000,000,007로 나눈 나머지를 return 하도록 solution 함수를 작성해주세요.</p>

<h5>제한사항</h5>

<ul>
<li>격자의 크기 m, n은 1 이상 100 이하인 자연수입니다.

<ul>
<li>m과 n이 모두 1인 경우는 입력으로 주어지지 않습니다.</li>
</ul></li>
<li>물에 잠긴 지역은 0개 이상 10개 이하입니다.</li>
<li>집과 학교가 물에 잠긴 경우는 입력으로 주어지지 않습니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>m</th>
<th>n</th>
<th>puddles</th>
<th>return</th>
</tr>
</thead>
        <tbody><tr>
<td>4</td>
<td>3</td>
<td>[[2, 2]]</td>
<td>4</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p><img src="https://asset.programmers.co.kr/files/ybm/32c67958d5/729216f3-f305-4ad1-b3b0-04c2ba0b379a.png" title="" alt="image1.png"></p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges


등굣길 (프로그래머스) — 오답 노트
1. 좌표 순서 뒤집기

문제에서 m, n은 각각 가로, 세로 순서로 주어진다. 보통 문제들은 세로(행) → 가로(열) 순으로 주는데 이 문제는 반대다.

puddles의 각 원소도 [x, y] 형태이므로, 2차원 배열에 표시할 때 인덱스를 바꿔야 한다.

cpp
cnt[puddles[i][1]-1][puddles[i][0]-1] = -1;   // [행] = y, [열] = x

예제의 웅덩이가 [2, 2]로 대칭이라 뒤집혀 있어도 통과해서 문제를 눈치채지 못했다.
→ 좌표가 대칭인 예제는 순서 검증에 쓸 수 없다. 비대칭 입력을 직접 만들어 확인할 것.

2. 모듈러는 매번 적용

경로 수는 최대 C(198, 99)까지 커져서 int, long long 모두 범위를 넘는다. 마지막에 한 번만 나머지를 취하면 이미 오버플로된 값이라 결과가 틀린다.

cpp
cnt[i][j] = (cnt[i][j-1] + cnt[i-1][j]) % 1000000007;   // 누적할 때마다

→ 덧셈 결과에 모듈러를 요구하는 문제는 예외 없이 매 연산마다 적용한다.
