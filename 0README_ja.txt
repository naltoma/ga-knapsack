遺伝的アルゴリズムによるナップサック問題最適か
	Naruaki TOMA
	tnal@ie.u-ryukyu.ac.jp
	http://www.eva.ie.u-ryukyu.ac.jp/~tnal/
	Mon Dec  5 15:19:04 JST 2005


＜目次＞
0. これは何？
1. 何の為に作ったの？
2. 開発環境
3. ファイル一覧
4. インストール（コンパイル）
5. 使い方
6. 最後に
X. 考えていたけどやらなかったTODO


＜本文＞
0. これは何？
　遺伝的アルゴリズムを用いたナップサック問題用の最適化プログラムです．
遺伝的アルゴリズムについては
	http://www.eva.ie.u-ryukyu.ac.jp/~tnal/2005/info3/
や，そこにある「参考文献・サイト」が参考になるでしょう．ナックサック問
題用の最適化プログラムそのものは，簡易バージョンを
	http://www.eva.ie.u-ryukyu.ac.jp/~tnal/Job/GA/Readme.html
にて公開していましたが，情報工学実験 II でも利用する事になったので，少
し改善しました．主な改善点は以下の通りです．

　＜改善点＞
　・ソースを読む必要は無いですが，読みたい人用にコメントを追加．
　・重みと価値を別々に記載出来るようにした．
　・-Wall コンパイル時に warning が出ないように修正．
　・ANSI C 準拠となるよう修正（気づいた点のみ）．


2. 開発環境
  OS: Mac OS X バージョン 10.4.3
  gcc: gcc version 4.0.0 20041026 (Apple Computer, Inc. build 4061)
  make: GNU Make 3.80
  bash: GNU bash, version 2.05b.0(1)-release (powerpc-apple-darwin8.0)

動作確認は Mac OS X でしかやっていませんが，ANSI標準ライブラリしか
使ってないので，環境に依存せずコンパイルできると思います．というか，元々
のソースは BSD/OS 4.0 で開発していたもので，昔確認した時点においては，
修正せずに Linux, Mac OS X 等で動いていたので，よほどの事が無い限り動
くでしょう．変わった事はやってませんし．


3. ファイル
./1-1-KP_List.data-10		# 実行例
./1-1-KP_List.data-10.end	# 実行例の最終結果
./1-1-KP_List.data-10.max	# 実行例の最大適応度推移(世代,価値,重量)

./KP_List.data	# 荷重ファイル
		#   (書式:int型で「価値 重量」を半角スペース区切りで列挙)
./KP.h		# ナップサック問題の定義
./parameter.h	# GAパラメータの定義

./Makefile
./KP.c			# 荷重ファイルを読み込む
./calc_fitness.c	# 適応度計算
./ga.c			# メイン関数
./initialize_gene_binary.c	# 初期集団作成
./kp.exe			# 実行ファイル
./mutation_binary.c		# 突然変異
./random2.c			# 乱数生成
./roulette_selection.c		# ルーレット選択
./singlepoint_crossover.c	# 一点交叉

./run_ga.sh		# 実行結果の切り出し

./mk_kp_problem.pl	# ナップサック問題生成スクリプト


4. インストール（コンパイル）
元々が，
　　http://www.eva.ie.u-ryukyu.ac.jp/~tnal/Job/GA/Readme.html
にあるように，遺伝子操作（選択・交叉・突然変異）を実装した場合と実装し
なかった場合とで探索挙動を考察するためのプログラムであった事もあり，こ
のプログラムでも各遺伝子操作を実装する/しないようにコンパイルする事が
できます．デフォルトでは 4.1 のように全てを実装した場合の動作を確認す
る事になります．

4.1. 選択+交叉+突然変異を実装
  prompt> make

4.2. 選択のみ実装
  prompt> make OPTION="-DSELECTION"

4.3. 交叉のみ実装
  prompt> make OPTION="-DCROSSOVER"

4.4. 突然変異のみ実装
  prompt> make OPTION="-DMUTATION"

4.5. 選択+交叉を実装
  prompt> make OPTION="-DSELECTION -DCROSSOVER"

など，-DSELECTION, -DCROSSOVER, -DMUTATION を組み合わせてコンパイルし
てください．


5. 使い方
実行時に，
	1）初期集団作成用シード値（下記の例では1），
	2）GAオペレータ用シード値（同様に1），
	3）荷重ファイル（同様にKP_List.data），
	4）終了世代数（同様に10）
を引数として渡す．

□実行例
	prompt> ./run_ga.sh 1 1 KP_List.data 10

■最大適応度推移のグラフ表示方法
	(ケース1: 適応度推移のみ出力)
	prompt> gnuplot
	gnuplot> set title 'Fitness transition'
	gnuplot> set xlabel 'Generation'
	gnuplot> set ylabel 'Value'
	gnuplot> plot "1-1-KP_List.data-10.max" using 2 with line

	(ケース2: 適応度と重量推移を出力)
	prompt> gnuplot
	gnuplot> set title 'Fitness transition with the weight'
	gnuplot> set xlabel 'Generation'
	gnuplot> set ylabel 'Value'
	gnuplot> set y2label 'Weight'
	gnuplot> plot "1-1-KP_List.data-10.max" using 2 axis x1y1 'Value' with line, "1-1-KP_List.data-10.max" using 3 axis x1y2 title 'Weight' wigh line


6. 最後に
質問・ご指摘等は當間（tnal@ie.u-ryukyu.ac.jp）まで．
更新するかどうかは（私に取っての）重要度と気分次第ですが・・・．
個人的利用以外の使用については連絡してもらえるとうれしいかも．
単純にどういう所で使われるのかが興味があるだけで，制約・制限
等を課す意図は全くありません．


X. 考えてはいたけどやらなかったTODO
・適応度推移図の自動作成．
　実験内の課題でもあるので，サンプルスクリプトは作っていません．
・並列型GA
　MPI使って数台〜数十台PCクラスタ環境で動作させるとか．
