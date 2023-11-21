# [Platinum I] Elephants - 8172 

[문제 링크](https://www.acmicpc.net/problem/8172) 

### 성능 요약

메모리: 49152 KB, 시간: 960 ms

### 분류

그리디 알고리즘, 순열 사이클 분할

### 제출 일자

2023년 6월 7일 08:14:24

### 문제 설명

<p>A parade of all elephants is to commence soon at the Byteotian zoo. The zoo employees have encouraged these enormous animals to form a single line, as the manager wills it to be the initial figure of the parade.</p>

<p>Unfortunately, the manager himself came to the parade and did not quite like what he saw - he had intended an entirely different order of the elephants. Therefore he enforced his ordering, claiming the animals would seem most majestic this way, and made the employees reorder the elephants accordingly.</p>

<p>As a pack of moving elephants can wreak havoc, the employees decided to have them rearranged by swapping one pair at a time. Luckily the animals need not stand next to each other in order to swap positions in the line. Making an elephant move, however, is not as easy as it sounds. In fact, the effort one has to put into it is proportional to the animal's mass. Hence, the effort involved in swapping a pair of elephants of respective masses m<sub>1</sub> and m<sub>2</sub> can be estimated by m<sub>1</sub>+m<sub>2</sub>. What is the minimum effort involved in rearranging the elephants according to manager's will?</p>

<p>Write a programme that:</p>

<ul>
	<li>reads from the standard input the masses of all elephants from the zoo, along with their current and desired order in the line,</li>
	<li>determines a sequence of elephant swaps leading from the initial to the desired order of animals in the line, such that this sequence minimises the summary effort involved in all the swaps,</li>
	<li>prints out the summary effort on the standard output.</li>
</ul>

### 입력 

 <p>The first line of the standard input contains a single integer n (2 ≤ n ≤ 1,000,000) denoting the number of elephants in the zoo. We assume that the elephants are numbered from 1 to n to simplify things. The second line holds n integers mi (100 ≤ mi ≤ 6,500 dla 1 ≤ i ≤ n) separated by single spaces and denoting the masses of respective elephants (in kilogrammes).</p>

<p>The third line of input contains n pairwise different integers a<sub>i</sub> (1 ≤ a<sub>i</sub> ≤ n) separated by single spaces and denoting the numbers of successive elephants in the initial ordering. The fourth line holds n pairwise different integers b<sub>i</sub> (1 ≤ b<sub>i</sub> ≤ n) separated by single spaces and denoting the numbers of successive elephants in the ordering desired by the zoo manager. You may assume that the sequences (a<sub>i</sub>) and (b<sub>i</sub>) differ.</p>

### 출력 

 <p>The first and only line of the standard output should contain a single integer denoting the minimum summary effort involved in reordering the elephants from the order represented by the sequence to the one represented by (b<sub>i</sub>).</p>

