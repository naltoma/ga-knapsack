#!/usr/bin/perl

# �ʥåץ��å���������������ץ�
#   Usage:
#      prompt> ./mk_kp_prob.pl $item_num
#           $item_num: ���������������ƥ��

srand(time);
my $num = @ARGV[0];

for($i=0; $i<$num; $i++){
    $value = int(rand(10000));
    $weight = int(rand(1000));
    printf("$value $weight\n");
}
