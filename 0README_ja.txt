����Ū���르�ꥺ��ˤ��ʥåץ��å������Ŭ��
	Naruaki TOMA
	tnal@ie.u-ryukyu.ac.jp
	http://www.eva.ie.u-ryukyu.ac.jp/~tnal/
	Mon Dec  5 15:19:04 JST 2005


���ܼ���
0. ����ϲ���
1. ���ΰ٤˺�ä��Ρ�
2. ��ȯ�Ķ�
3. �ե��������
4. ���󥹥ȡ���ʥ���ѥ����
5. �Ȥ���
6. �Ǹ��
X. �ͤ��Ƥ������ɤ��ʤ��ä�TODO


����ʸ��
0. ����ϲ���
������Ū���르�ꥺ����Ѥ����ʥåץ��å������Ѥκ�Ŭ���ץ����Ǥ���
����Ū���르�ꥺ��ˤĤ��Ƥ�
	http://www.eva.ie.u-ryukyu.ac.jp/~tnal/2005/info3/
�䡤�����ˤ���ֻ���ʸ���������ȡפ����ͤˤʤ�Ǥ��礦���ʥå����å���
���Ѥκ�Ŭ���ץ���ऽ�Τ�Τϡ��ʰץС�������
	http://www.eva.ie.u-ryukyu.ac.jp/~tnal/Job/GA/Readme.html
�ˤƸ������Ƥ��ޤ����������󹩳ؼ¸� II �Ǥ����Ѥ�����ˤʤä��Τǡ���
���������ޤ�������ʲ������ϰʲ����̤�Ǥ���

�����������
�������������ɤ�ɬ�פ�̵���Ǥ������ɤߤ������Ѥ˥����Ȥ��ɲá�
�����ŤߤȲ��ͤ��̡��˵��ܽ����褦�ˤ�����
����-Wall ����ѥ������ warning ���Фʤ��褦�˽�����
����ANSI C ���Ȥʤ�褦�����ʵ��Ť������Τߡˡ�


2. ��ȯ�Ķ�
  OS: Mac OS X �С������ 10.4.3
  gcc: gcc version 4.0.0 20041026 (Apple Computer, Inc. build 4061)
  make: GNU Make 3.80
  bash: GNU bash, version 2.05b.0(1)-release (powerpc-apple-darwin8.0)

ư���ǧ�� Mac OS X �Ǥ�����äƤ��ޤ��󤬡�ANSIɸ��饤�֥�ꤷ��
�ȤäƤʤ��Τǡ��Ķ��˰�¸��������ѥ���Ǥ���Ȼפ��ޤ����Ȥ�����������
�Υ������� BSD/OS 4.0 �ǳ�ȯ���Ƥ�����Τǡ��γ�ǧ���������ˤ����Ƥϡ�
���������� Linux, Mac OS X ����ư���Ƥ����Τǡ���ۤɤλ���̵���¤�ư
���Ǥ��礦���Ѥ�ä����Ϥ�äƤޤ��󤷡�


3. �ե�����
./1-1-KP_List.data-10		# �¹���
./1-1-KP_List.data-10.end	# �¹���κǽ����
./1-1-KP_List.data-10.max	# �¹���κ���Ŭ���ٿ��(����,����,����)

./KP_List.data	# �ٽťե�����
		#   (��:int���ǡֲ��� ���̡פ�Ⱦ�ѥ��ڡ������ڤ�����)
./KP.h		# �ʥåץ��å���������
./parameter.h	# GA�ѥ�᡼�������

./Makefile
./KP.c			# �ٽťե�������ɤ߹���
./calc_fitness.c	# Ŭ���ٷ׻�
./ga.c			# �ᥤ��ؿ�
./initialize_gene_binary.c	# ������ĺ���
./kp.exe			# �¹ԥե�����
./mutation_binary.c		# �����Ѱ�
./random2.c			# �������
./roulette_selection.c		# �롼��å�����
./singlepoint_crossover.c	# ������

./run_ga.sh		# �¹Է�̤��ڤ�Ф�

./mk_kp_problem.pl	# �ʥåץ��å���������������ץ�


4. ���󥹥ȡ���ʥ���ѥ����
��������
����http://www.eva.ie.u-ryukyu.ac.jp/~tnal/Job/GA/Readme.html
�ˤ���褦�ˡ��������������򡦸򺵡������Ѱۡˤ�����������ȼ�����
�ʤ��ä����Ȥ�õ����ư��ͻ����뤿��Υץ����Ǥ��ä����⤢�ꡤ��
�Υץ����Ǥ�ư����������������/���ʤ��褦�˥���ѥ��뤹�����
�Ǥ��ޤ����ǥե���ȤǤ� 4.1 �Τ褦�����Ƥ������������ư����ǧ��
����ˤʤ�ޤ���

4.1. ����+��+�����Ѱۤ����
  prompt> make

4.2. ����Τ߼���
  prompt> make OPTION="-DSELECTION"

4.3. �򺵤Τ߼���
  prompt> make OPTION="-DCROSSOVER"

4.4. �����ѰۤΤ߼���
  prompt> make OPTION="-DMUTATION"

4.5. ����+�򺵤����
  prompt> make OPTION="-DSELECTION -DCROSSOVER"

�ʤɡ�-DSELECTION, -DCROSSOVER, -DMUTATION ���Ȥ߹�碌�ƥ���ѥ��뤷
�Ƥ���������


5. �Ȥ���
�¹Ի��ˡ�
	1�˽�����ĺ����ѥ������͡ʲ�������Ǥ�1�ˡ�
	2��GA���ڥ졼���ѥ������͡�Ʊ�ͤ�1�ˡ�
	3�˲ٽťե������Ʊ�ͤ�KP_List.data�ˡ�
	4�˽�λ�������Ʊ�ͤ�10��
������Ȥ����Ϥ���

���¹���
	prompt> ./run_ga.sh 1 1 KP_List.data 10

������Ŭ���ٿ�ܤΥ����ɽ����ˡ
	(������1: Ŭ���ٿ�ܤΤ߽���)
	prompt> gnuplot
	gnuplot> set title 'Fitness transition'
	gnuplot> set xlabel 'Generation'
	gnuplot> set ylabel 'Value'
	gnuplot> plot "1-1-KP_List.data-10.max" using 2 with line

	(������2: Ŭ���٤Ƚ��̿�ܤ����)
	prompt> gnuplot
	gnuplot> set title 'Fitness transition with the weight'
	gnuplot> set xlabel 'Generation'
	gnuplot> set ylabel 'Value'
	gnuplot> set y2label 'Weight'
	gnuplot> plot "1-1-KP_List.data-10.max" using 2 axis x1y1 'Value' with line, "1-1-KP_List.data-10.max" using 3 axis x1y2 title 'Weight' wigh line


6. �Ǹ��
���䡦����Ŧ�����Ĵ֡�tnal@ie.u-ryukyu.ac.jp�ˤޤǡ�
�������뤫�ɤ����ϡʻ�˼�äƤΡ˽����٤ȵ�ʬ����Ǥ�����������
�Ŀ�Ū���Ѱʳ��λ��ѤˤĤ��Ƥ�Ϣ���Ƥ�館��Ȥ��줷�����⡥
ñ��ˤɤ�������ǻȤ���Τ�����̣����������ǡ���������
����ݤ��տޤ���������ޤ���


X. �ͤ��ƤϤ������ɤ��ʤ��ä�TODO
��Ŭ���ٿ�ܿޤμ�ư������
���¸���β���Ǥ⤢��Τǡ�����ץ륹����ץȤϺ�äƤ��ޤ���
������GA
��MPI�Ȥäƿ����������PC���饹���Ķ���ư�����Ȥ���
