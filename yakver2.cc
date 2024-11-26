//#include <cstdint>
#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


enum ihan {
  tanyao = 1,
  tumo,
  jikaze,
  bakaze,
  sangen,
  pinfu,
  ipeko,
  chankan,
  rinshan,
  haitei,
  houtei,
  reach,
  ippatu,

};

enum ryanhan {
  sanshokDK = 14,
  sankantu,
  toitoi,
  sananko,
  shosangen,
  konroto,
  titoitu,
  tyanta,
  ittu,
  sanshokDJ,
  doublereach,

};

enum sanhan {
  ryanpeko = 25,
  juntyan,
  honitu,

};

enum rokuhan { tinitu = 28 };

enum yakman {
  tenho = 29,
  tiho,
  sukantu,
  tuiso,
  daisangen,
  tinroto,
  ryuiso,
  shosushi,
  suanko,
  kokushi,
  tyuren,

};

enum doubleyakman {
  suankotanki = 40,
  daisushi,
  kokushijusan,
  junseityuren,
};

std::random_device rd;
std::mt19937 gen(rd());
//疑似乱数1(旧)
/*int random(int low, int high) {
  std::uniform_int_distribution<> dist(low, high);
  return dist(gen);
}*/

//疑似乱数(役抽選で使用)
int random2(int High) {
  int x;
  srand(time(NULL));
  x = rand() % High + 1;

  return x;
}

//役の足し算
int yakadd(int yak, int x) { return yak + x; }

//動作確認用役出力
int yakoutput(int yk[], int i) {
  int j;
  int keep;

  keep = i;
  std::cout << "今回の役は" << std::ends;
  for (j = 0; j < 13; j++) {
    switch (yk[j]) {
    case tanyao:
      std::cout << "断幺九," << std::ends;
      break;

    case tumo:
      std::cout << "ツモ," << std::ends;
      break;

    case jikaze:
      std::cout << "役牌:自風牌," << std::ends;
      break;

    case bakaze:
      std::cout << "役牌:場風牌," << std::ends;
      break;

    case sangen:
      std::cout << "役牌:三元牌," << std::ends;
      break;

    case pinfu:
      std::cout << "平和," << std::ends;
      break;

    case ipeko:
      std::cout << "一盃口," << std::ends;
      break;

    case chankan:
      std::cout << "槍槓," << std::ends;
      break;

    case rinshan:
      std::cout << "嶺上開花," << std::ends;
      break;

    case haitei:
      std::cout << "海底摸月," << std::ends;
      break;

    case houtei:
      std::cout << "河底撈魚," << std::ends;
      break;

    case reach:
      std::cout << "立直," << std::ends;
      break;

    case ippatu:
      std::cout << "一発," << std::ends;
      break;

    case sanshokDK:
      std::cout << "三色同刻," << std::ends;
      break;

    case sankantu:
      std::cout << "三槓子," << std::ends;
      break;

    case toitoi:
      std::cout << "対々和," << std::ends;
      break;

    case sananko:
      std::cout << "三暗刻," << std::ends;
      break;

    case shosangen:
      std::cout << "小三元," << std::ends;
      break;

    case konroto:
      std::cout << "混老頭," << std::ends;
      break;

    case titoitu:
      std::cout << "七対子," << std::ends;
      break;

    case tyanta:
      std::cout << "混全帯幺九," << std::ends;
      break;

    case sanshokDJ:
      std::cout << "三色同順," << std::ends;
      break;

    case ittu:
      std::cout << "一気通貫," << std::ends;
      break;

    case doublereach:
      std::cout << "ダブル立直," << std::ends;
      break;

    case ryanpeko:
      std::cout << "二盃口," << std::ends;
      break;

    case juntyan:
      std::cout << "純正帯幺九," << std::ends;
      break;

    case honitu:
      std::cout << "混一色," << std::ends;
      break;

    case tinitu:
      std::cout << "清一色," << std::ends;
      break;
    }
  }
  std::cout << "の" << keep << "飜でした" << std::endl;

  return 0;
}

int yakumanoutput(int yk[]) { return 0; }

//平和の抽選
int pinfuflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if (a <= 215) {
    x = 1;
  } else if (a <= 900) {
    x = 2;
  } else if (a > 900) {
    x = 3;
  }

  return x;
}

//七対子の抽選
int titoituflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if (a <= 24) {
    x = 1;
  } else if (a <= 900) {
    x = 2;
  } else if (a > 900) {
    x = 3;
  }

  return x;
}

//清一色の抽選
int tinituflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if (a <= 8) {
    x = 1;
  } else if (a <= 900) {
    x = 2;
  } else if (a > 900) {
    x = 3;
  }

  return x;
}

//混一色の抽選
int honituflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if (a <= 63) {
    x = 1;
  } else if (a <= 900) {
    x = 2;
  } else if (a > 900) {
    x = 3;
  }

  return x;
}

//混老頭の抽選
int konrotoflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if (a <= 1) {
    x = 1;
  } else if (a <= 900) {
    x = 2;
  } else if (a > 900) {
    x = 3;
  }

  return x;
}

//二盃口の抽選
int ryanpekoflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if (a <= 1) {
    x = 1;
  } else if (a <= 900) {
    x = 2;
  } else if (a > 900) {
    x = 3;
  }

  return x;
}

//三色同順の抽選
int doujunflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if (a <= 38) {
    x = 1;
  } else if (a <= 900) {
    x = 2;
  } else if (a > 900) {
    x = 3;
  }

  return x;
}

//対々和の抽選
int toitoiflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if (a <= 32) {
    x = 1;
  } else if (a <= 900) {
    x = 2;
  } else if (a > 900) {
    x = 3;
  }

  return x;
}

//三槓子の抽選
int sankantuflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(100000);
  if (a <= 5) {
    x = 1;
  } else if (a <= 90000) {
    x = 2;
  } else if (a > 90000) {
    x = 3;
  }

  return x;
}

//三暗刻の抽選
int sanankoflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if (a <= 7) {
    x = 1;
  } else if (a <= 900) {
    x = 2;
  } else if (a > 900) {
    x = 3;
  }

  return x;
}

//三色同刻の抽選
int doukoflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(10000);
  if (a <= 4) {
    x = 1;
  } else if (a <= 9000) {
    x = 2;
  } else if (a > 9000) {
    x = 3;
  }

  return x;
}

//純正チャンタの抽選
int juntyanflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if (a <= 4) {
    x = 1;
  } else if (a <= 900) {
    x = 2;
  } else if (a > 900) {
    x = 3;
  }

  return x;
}

//一気通貫の抽選
int ittuflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if (a <= 18) {
    x = 1;
  } else if (a <= 900) {
    x = 2;
  } else if (a > 900) {
    x = 3;
  }

  return x;
}

//チャンタの抽選
int tyantaflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if (a <= 10) {
    x = 1;
  } else if (a <= 900) {
    x = 2;
  } else if (a > 900) {
    x = 3;
  }

  return x;
}

//一盃口の抽選
int ipekoflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if (a <= 46) {
    x = 1;
  } else if (a <= 900) {
    x = 2;
  } else if (a > 900) {
    x = 3;
  }

  return x;
}

//嶺上開花の抽選
int rinshanflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if ((a <= 3) && (flag == 1)) {
    x = 1;
  } else if (a <= 900) {
    x = 2;
  } else if (a > 900) {
    x = 3;
  }

  return x;
}

//小三元の抽選
int shosangenflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if (a <= 1) {
    x = 1;
  } else if (a <= 900) {
    x = 2;
  } else if (a > 900) {
    x = 3;
  }

  return x;
}

//風牌の抽選
int kazehaiflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if (a <= 165) {
    x = 1;
  } else if (a <= 330) {
    x = 2;
  } else if ((a <= 495) && ((flag == 1) || (flag == 2))) {
    x = 3;
  } else {
    x = 4;
  }

  return x;
}

//三元牌の抽選
int sangenflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if (a <= 165) {
    x = 1;
  } else if (a <= 330) {
    x = 2;
  } else if (a <= 495) {
    x = 3;
  } else {
    x = 4;
  }

  return x;
}

//海底の抽選
int haiteiflag(int flag) {
  int a = 0;
  int x = 0;

  a = random2(1000);
  if (a <= 9) {
    x = 1;
  } else {
    x = 2;
  }

  return x;
}

//海底の処理
int haiteichose(int yk[],int yak, int tumoflag, int rinflag){
  int kakuritu=0;
  int yakflag=0;

  yakflag=haiteiflag(yakflag);
  std::cout << "海底フラグ" << yakflag << std::endl;


  switch(yakflag){
    //海底あり
    case 1:
      if((tumoflag==1)&&(rinflag==0)){
        yk[0]=haitei;
        yak=yakadd(yak , 1);
      }else if((tumoflag==0)&&(rinflag==0)){
        yk[0]=houtei;
        yak=yakadd(yak,1);
      }
    //海底なし
      case 2:

      yakoutput(yk,yak);
    break;
  }

  return 0;
}

int sangenhai(){
  int x;
  int i=0;

  x=random2(100);

  if((x%3)==0){
    i=1;
  }

  return i;
}

//面前での役抽選
int menzen(int yk[], int yak, int oyaflag, int reach) {
  int yakflag;
  int kakuritu;
  int tumoflag = 0;
  int rinflag = 0;
  int hakuflag = 0;
  int hatuflag = 0;
  int tyunflag = 0;
  int x = 0;

  yakflag = 0;
  kakuritu = random2(1000);

  // ツモの有無
  if (kakuritu <= 188) {
    yakflag = 1;
  } else {
    yakflag = 2;
  }

  std::cout << "ツモフラグ" << yakflag << std::endl;

  switch (yakflag) {
  // ツモ
  case 1:
    yk[3] = tumo;
    yak = yakadd(yak, 1);
    tumoflag = 1;

  // ロン
  case 2:
    kakuritu = 0;
    yakflag = 0;

    kakuritu = random2(1000);
    // タンヤオの有無

    if (kakuritu <= 224) {
      yakflag = 1;
    } else if (kakuritu <= 900) {
      yakflag = 2;
    } else if (kakuritu > 900) {
      yakflag = 3;
    }
    std::cout << "タンヤオフラグ" << yakflag << std::endl;

    switch (yakflag) {
    // タンヤオあり
    case 1:
      yk[4] = tanyao;
      yak = yakadd(yak, 1);
      yakflag = 0;

      yakflag = pinfuflag(yakflag);
      // 平和の有無
      std::cout << "平和フラグ" << yakflag << std::endl;

      switch (yakflag) {
      // 平和有
      case 1:
        yk[5] = pinfu;
        yak = yakadd(yak, 1);
        yakflag = 0;

        yakflag = tinituflag(yakflag);
        // 清一色の有無
        std::cout << "清一色フラグ" << yakflag << std::endl;

        switch (yakflag) {
        // 清一色有
        case 1:
          yk[6] = tinitu;
          yak = yakadd(yak, 6);
          yakflag = 0;
          yakflag = ryanpekoflag(yakflag);
          // 二盃口の有無
          std::cout << "二盃口フラグ" << yakflag << std::endl;

          switch (yakflag) {
          // 二盃口有
          case 1:
            yk[7] = ryanpeko;
            yak = yakadd(yak, 3);

            haiteichose(yk,yak,tumoflag,rinflag);
            break;
          // 二盃口無し
          case 2:
            yakflag = 0;
            yakflag = ipekoflag(yakflag);
            std::cout << "一盃口フラグ" << yakflag << std::endl;

            switch (yakflag) {
            case 1:
              yk[7] = ipeko;
              yak = yakadd(yak, 1);
            case 2:
            case 3:

              haiteichose(yk,yak,tumoflag,rinflag);
              break;
            }
            break;
          // 役決定
          case 3:

            haiteichose(yk,yak,tumoflag,rinflag);
            break;
          }

          break;

        // 清一色無
        case 2:
          yakflag = 0;
          yakflag = ryanpekoflag(yakflag);
          std::cout << "二盃口フラグ" << yakflag << std::endl;

          switch (yakflag) {
          // 二盃口有
          case 1:
            yk[7] = ryanpeko;
            yak = yakadd(yak, 3);

            haiteichose(yk,yak,tumoflag,rinflag);

            break;

          case 2:
            yakflag = 0;
            yakflag = doujunflag(yakflag);
            std::cout << "三色同順フラグ" << yakflag << std::endl;

            switch (yakflag) {
            // 三色同順あり
            case 1:
              yk[6] = sanshokDJ;
              yak = yakadd(yak, 2);

            // 三色同順無し
            case 2:
              yakflag = 0;
              yakflag = ipekoflag(yakflag);
              std::cout << "一盃口フラグ" << yakflag << std::endl;

              switch (yakflag) {
              // 一盃口有
              case 1:
                yk[7] = ipeko;
                yak = yakadd(yak, 1);

                haiteichose(yk,yak,tumoflag,rinflag);

                break;
              // 一盃口無し
              case 2:
              // 役決定
              case 3:

                haiteichose(yk,yak,tumoflag,rinflag);

                break;
              }
              break;

            // 役決定
            case 3:

              haiteichose(yk,yak,tumoflag,rinflag);
              break;
            }
            break;
          // 役決定
          case 3:

            haiteichose(yk,yak,tumoflag,rinflag);
            break;
          }
          break;

        // 役の決定
        case 3:

          haiteichose(yk,yak,tumoflag,rinflag);
          break;
        }
        break;
      // 平和無し
      case 2:
        yakflag = 0;
        yakflag = titoituflag(yakflag);
        std::cout << "七対子フラグ" << yakflag << std::endl;

        switch (yakflag) {
        // 七対子あり
        case 1:
          yk[6] = titoitu;
          yak = yakadd(yak, 2);

          haiteichose(yk,yak,tumoflag,rinflag);

          break;
        // 七対子無
        case 2:
          yakflag = 0;
          yakflag = rinshanflag(yakflag);
          std::cout << "嶺上開花フラグ" << yakflag << std::endl;

          switch (yakflag) {
          case 1:
            yk[0] = rinshan;
            yak = yakadd(yak, 1);
          case 2:
            yakflag = 0;
            yakflag = tinituflag(yakflag);
            std::cout << "清一色フラグ" << yakflag << std::endl;

            switch (yakflag) {
            // 清一色有
            case 1:
              yk[6] = tinitu;
              yak = yakadd(yak, 6);

              yakflag = 0;
              yakflag = toitoiflag(yakflag);
              std::cout << "対々和フラグ" << yakflag << std::endl;

              switch (yakflag) {
              // 対々和有
              case 1:
                if (tumoflag == 1) {
                  yk[1] = suanko;
                  yakumanoutput(yk);

                } else if (tumoflag == 0) {
                  yk[7] = toitoi;
                  yk[8] = sananko;
                  yak = yakadd(yak, 4);

                  yakflag = 0;
                  yakflag = sankantuflag(yakflag);
                  std::cout << "三槓子フラグ" << yakflag << std::endl;
                  switch (yakflag) {
                  case 1:
                    yk[9] = sankantu;
                    yak = yakadd(yak, 2);

                    haiteichose(yk,yak,tumoflag,rinflag);
                    break;

                  // 三槓子無
                  case 2:
                  // 役決定
                  case 3:
        
                    haiteichose(yk,yak,tumoflag,rinflag);
                    break;
                  }
                }

                break;
              // 対々和無
              case 2:
                yakflag = 0;
                yakflag = sanankoflag(yakflag);

                switch (yakflag) {
                // 三暗刻有
                case 1:
                  yk[7] = sananko;
                  yak = yakadd(yak, 2);

                  yakflag = 0;
                  yakflag = sankantuflag(yakflag);

                  switch (yakflag) {
                  // 三槓子有
                  case 1:
                    yk[8] = sankantu;
                    yak = yakadd(yak, 2);

                  // 三槓子無
                  case 2:
                  case 3:

                    haiteichose(yk,yak,tumoflag,rinflag);

                    break;
                  }
                  break;

                // 三暗刻無
                case 2:
                // 役決定
                case 3:

                  haiteichose(yk,yak,tumoflag,rinflag);
                  break;
                }
                break;
              // 役決定
              case 3:

                haiteichose(yk,yak,tumoflag,rinflag);
                break;
              }
              break;

            // 清一色無
            case 2:
              yk[6] = tinitu;
              yak = yakadd(yak, 6);

              yakflag = 0;
              yakflag = toitoiflag(yakflag);
              std::cout << "対々和フラグ" << yakflag << std::endl;

              switch (yakflag) {
              // 対々和有
              case 1:
                if (tumoflag == 1) {
                  yk[1] = suanko;
                  yakumanoutput(yk);

                } else if (tumoflag == 0) {
                  yk[7] = toitoi;
                  yk[8] = sananko;
                  yak = yakadd(yak, 4);

                  yakflag = 0;
                  yakflag = sankantuflag(yakflag);
                  std::cout << "三槓子フラグ" << yakflag << std::endl;
                  switch (yakflag) {
                  case 1:
                    yk[9] = sankantu;
                    yak = yakadd(yak, 2);
                    yakflag = 0;
                    yakflag = doukoflag(yakflag);
                    std::cout << "三色同刻フラグ" << yakflag << std::endl;
                    switch (yakflag) {
                    case 1:
                      yk[10] = sanshokDK;
                      yak = yakadd(yak, 2);
                    case 2:
                    case 3:
              
                      haiteichose(yk,yak,tumoflag,rinflag);

                      break;
                    }

                    break;

                  // 三槓子無
                  case 2:
                  // 役決定
                  case 3:

                    haiteichose(yk,yak,tumoflag,rinflag);
                    break;
                  }
                }

                break;

              // 対々和無
              case 2:
                yakflag = 0;
                yakflag = sanankoflag(yakflag);

                switch (yakflag) {
                // 三暗刻有
                case 1:
                  yk[7] = sananko;
                  yak = yakadd(yak, 2);

                  yakflag = 0;
                  yakflag = sankantuflag(yakflag);

                  switch (yakflag) {
                  // 三槓子有
                  case 1:
                    yk[8] = sankantu;
                    yak = yakadd(yak, 2);

                  // 三槓子無
                  case 2:
                    yakflag = 0;
                    yakflag = doukoflag(yakflag);

                    switch (yakflag) {
                    case 1:
                      yk[9] = sanshokDK;
                      yak = yakadd(yak, 2);
                    case 2:
                    case 3:

                      haiteichose(yk,yak,tumoflag,rinflag);
                      break;
                    }
                    break;

                  case 3:

                    haiteichose(yk,yak,tumoflag,rinflag);
                    break;
                  }
                  break;

                // 三暗刻無
                case 2:
                // 役決定
                case 3:
    
                  haiteichose(yk,yak,tumoflag,rinflag);
                  break;
                }
                break;
              // 役決定
              case 3:

                haiteichose(yk,yak,tumoflag,rinflag);
                break;
              }
              break;

            // 役決定
            case 3:

              haiteichose(yk,yak,tumoflag,rinflag);
              break;
            }
            break;

          case 3:

            haiteichose(yk,yak,tumoflag,rinflag);
            break;
          }

          break;
        // 役決定
        case 3:

          haiteichose(yk,yak,tumoflag,rinflag);
          break;
        }
        break;
      // 役決定
      case 3:

        haiteichose(yk,yak,tumoflag,rinflag);
        break;
      }
      break;

      // タンヤオ無し

    case 2:
      yakflag = 0;
      yakflag = pinfuflag(yakflag);
      std::cout << "平和フラグ" << yakflag << std::endl;

      switch (yakflag) {
      // 平和有
      case 1:
        yk[5] = pinfu;
        yak = yakadd(yak, 1);
        yakflag = 0;
        yakflag = tinituflag(yakflag);
        std::cout << "清一色フラグ" << yakflag << std::endl;
        switch (yakflag) {
        // 清一色有
        case 1:
          yk[6] = tinitu;
          yak = yakadd(yak, 6);
          yakflag = 0;
          yakflag = ryanpekoflag(yakflag);
          std::cout << "二盃口フラグ" << yakflag << std::endl;

          switch (yakflag) {
          // 二盃口有
          case 1:
            yk[7] = ryanpeko;
            yak = yakadd(yak, 3);
            yakflag = 0;
            yakflag = juntyanflag(yakflag);
            std::cout << "純全帯么九フラグ" << yakflag << std::endl;

            switch (yakflag) {
            case 1:
              yk[8] = juntyan;
              yak = yakadd(yak, 3);
            case 2:
            case 3:

              haiteichose(yk,yak,tumoflag,rinflag);
              break;
            }
            break;

          // 二盃口無
          case 2:
            yakflag = 0;
            yakflag = ittuflag(yakflag);
            std::cout << "一気通貫フラグ" << yakflag << std::endl;

            switch (yakflag) {
            case 1:
              yk[7] = ittu;
              yak = yakadd(yak, 2);
            case 2:
              yakflag = 0;
              yakflag = ipekoflag(yakflag);
              std::cout << "一盃口フラグ" << yakflag << std::endl;
              switch (yakflag) {
              case 1:
                yk[8] = ipeko;
                yak = yakadd(yak, 1);
              case 2:
              case 3:

                haiteichose(yk,yak,tumoflag,rinflag);
                break;
              }
              break;

            case 3:

              haiteichose(yk,yak,tumoflag,rinflag);
              break;
            }
            break;

          // 役決定
          case 3:

            haiteichose(yk,yak,tumoflag,rinflag);
            break;
          }
          break;

        // 清一色無
        case 2:
          yakflag = 0;
          yakflag = honituflag(yakflag);
          std::cout << "混一色" << yakflag << std::endl;

          switch (yakflag) {
          // ホンイツ有
          case 1:
            yk[6] = honitu;
            yak = yakadd(yak, 3);

            yakflag = 0;
            yakflag = ryanpekoflag(yakflag);
            std::cout << "二盃口フラグ" << yakflag << std::endl;

            switch (yakflag) {
            case 1:
              yk[7] = ryanpeko;
              yak = yakadd(yak, 3);

              yakflag = 0;
              yakflag = tyantaflag(yakflag);
              std::cout << "チャンタフラグ" << yakflag << std::endl;

              switch (yakflag) {
              case 1:
                yk[8] = tyanta;
                yak = yakadd(yak, 2);
              case 2:
              case 3:

                haiteichose(yk,yak,tumoflag,rinflag);
                break;
              }
              break;

            case 2:
              yakflag = 0;
              yakflag = ittuflag(yakflag);
              std::cout << "一気通貫フラグ" << std::endl;

              switch (yakflag) {
              case 1:
                yk[7] = ittu;
                yak = yakadd(yak, 2);

              case 2:
                yakflag = 0;
                yakflag = ipekoflag(yakflag);

                switch (yakflag) {
                case 1:
                  yk[8] = ipeko;
                  yak = yakadd(yak, 1);
                case 2:
                case 3:

                  haiteichose(yk,yak,tumoflag,rinflag);
                  break;
                }
                break;

              case 3:

                haiteichose(yk,yak,tumoflag,rinflag);
                break;
              }
              break;

            case 3:

              haiteichose(yk,yak,tumoflag,rinflag);
              break;
            }
            break;

          // ホンイツ無
          case 2:
            yakflag = 0;
            yakflag = juntyanflag(yakflag);
            std::cout << "純チャンフラグ" << yakflag << std::endl;

            switch (yakflag) {
            case 1:
              yk[6] = juntyan;
              yak = yakadd(yak, 3);

              yakflag = 0;
              yakflag = ryanpekoflag(yakflag);
              std::cout << "二盃口フラグ" << yakflag << std::endl;

              switch (yakflag) {
              case 1:
                yk[7] = ryanpeko;
                yak = yakadd(yak, 3);

                haiteichose(yk,yak,tumoflag,rinflag);
                break;

              case 2:
                yakflag = 0;
                yakflag = doujunflag(yakflag);

                switch (yakflag) {
                case 1:
                  yk[7] = sanshokDJ;
                  yak = yakadd(yak, 2);

                case 2:
                  yakflag = 0;
                  yakflag = ipekoflag(yakflag);

                  switch (yakflag) {
                  case 1:
                    yk[8] = ipeko;
                    yak = yakadd(yak, 1);
                  case 2:
                  case 3:

                    haiteichose(yk,yak,tumoflag,rinflag);
                    break;
                  }
                  break;

                case 3:

                  haiteichose(yk,yak,tumoflag,rinflag);
                  break;
                }
                break;

              case 3:

                haiteichose(yk,yak,tumoflag,rinflag);
                break;
              }
              break;

            case 2:
              yakflag = 0;
              yakflag = tyantaflag(yakflag);
              std::cout << "チャンタフラグ" << yakflag << std::endl;

              switch (yakflag) {
              case 1:
                yk[6] = tyanta;
                yak = yakadd(yak, 2);

                yakflag = 0;
                yakflag = ryanpekoflag(yakflag);
                std::cout << "二盃口フラグ" << yakflag << std::endl;

                switch (yakflag) {
                case 1:
                  yk[7] = ryanpeko;
                  yak = yakadd(yak, 3);

                  haiteichose(yk,yak,tumoflag,rinflag);
                  break;

                case 2:
                  yakflag = 0;
                  yakflag = doujunflag(yakflag);

                  switch (yakflag) {
                  case 1:
                    yk[7] = sanshokDJ;
                    yak = yakadd(yak, 2);

                  case 2:
                    yakflag = 0;
                    yakflag = ipekoflag(yakflag);

                    switch (yakflag) {
                    case 1:
                      yk[8] = ipeko;
                      yak = yakadd(yak, 1);
                    case 2:
                    case 3:

                      haiteichose(yk,yak,tumoflag,rinflag);
                      break;
                    }
                    break;

                  case 3:

                    haiteichose(yk,yak,tumoflag,rinflag);
                    break;
                  }
                  break;

                case 3:

                  haiteichose(yk,yak,tumoflag,rinflag);
                  break;
                }

                break;

              case 2:
                yakflag = 0;
                yakflag = ittuflag(yakflag);
                std::cout << "一気通貫フラグ" << yakflag << std::endl;

                switch (yakflag) {
                case 1:
                  yk[7] = ittu;
                  yak = yakadd(yak, 2);
                case 2:
                  yakflag = 0;
                  yakflag = ipekoflag(yakflag);
                  std::cout << "一盃口フラグ" << yakflag << std::endl;

                  switch (yakflag) {
                  case 1:
                    yk[8] = ipeko;
                    yak = yakadd(yak, 1);
                  case 2:
                  case 3:

                    haiteichose(yk,yak,tumoflag,rinflag);
                    break;
                  }
                  break;

                case 3:

                  haiteichose(yk,yak,tumoflag,rinflag);
                  break;
                }
                break;

              case 3:

                haiteichose(yk,yak,tumoflag,rinflag);
                break;
              }
              break;

            case 3:

              haiteichose(yk,yak,tumoflag,rinflag);
              break;
            }
            break;

          // 役決定
          case 3:

            haiteichose(yk,yak,tumoflag,rinflag);
            break;
          }
          break;
        // 役決定
        case 3:

          haiteichose(yk,yak,tumoflag,rinflag);
          break;
        }
        break;

      // 平和無し
      case 2:
        yakflag = titoituflag(yakflag);
        std::cout<<"七対子フラグ"<<yakflag<<std::endl;
        switch (yakflag) {
        // 七対子あり
        case 1:
          yk[6] = titoitu;
          yak = yakadd(yak, 2);

          yakflag = 0;
          yakflag = tinituflag(yakflag);
          std::cout << "清一色" << yakflag << std::endl;

          switch (yakflag) {
          // 清一色あり
          case 1:
            yk[7] = tinitu;
            yak = yakadd(yak, 6);

            haiteichose(yk,yak,tumoflag,rinflag);
            break;

            // 清一色無し

          case 2:
            yakflag = honituflag(yakflag);
            std::cout << "混一色フラグ" << yakflag << std::endl;

            switch (yakflag) {
            case 1:
              yk[7] = honitu;
              yak = yakadd(yak, 3);

            case 2:
              yakflag = 0;
              yakflag = konrotoflag(yakflag);
              std::cout << "混老頭フラグ" << yakflag << std::endl;

              switch (yakflag) {
              case 1:
                yk[8] = konroto;
                yak = yakadd(yak, 2);

              case 2:
              case 3:

                haiteichose(yk,yak,tumoflag,rinflag);
                break;
              }
              break;

              // 役決定
            case 3:

              haiteichose(yk,yak,tumoflag,rinflag);
              break;
            }
            break;
          // 役決定
          case 3:

            haiteichose(yk,yak,tumoflag,rinflag);
            break;
          }
          break;

        // 七対子無
        case 2:
          yakflag = 0;
          yakflag = rinshanflag(tumoflag);
          std::cout<<"嶺上開花フラグ"<<yakflag<<std::endl;

          switch (yakflag) {
          case 1:
            yk[0] = rinshan;
            yak = yakadd(yak, 1);
            rinflag = 1;
          case 2:
            yakflag = 0;
            yakflag = tinituflag(yakflag);
            std::cout<<"清一色フラグ"<<yakflag<<std::endl;

            switch (yakflag) {
            case 1:
              yk[5] = tinitu;
              yak = yakadd(yak, 6);

              yakflag = 0;
              yakflag = toitoiflag(yakflag);
              std::cout << "対々和フラグ" << yakflag << std::endl;

              switch (yakflag) {
              case 1:
                if (tumoflag == 1) {
                  yk[0] = suanko;
                  yakumanoutput(yk);
                } else if (tumoflag == 0) {
                  yk[6] = toitoi;
                  yk[7] = sananko;
                  yak = yakadd(yak, 4);

                  yakflag = 0;
                  yakflag = sankantuflag(yakflag);
                  std::cout << "三槓子フラグ" << yakflag << std::endl;

                  switch (yakflag) {
                  case 1:
                    yk[8] = sankantu;
                    yak = yakadd(yak, 2);
                  case 2:
                  case 3:
                   
                    haiteichose(yk,yak,tumoflag,rinflag);
                    break;
                  }
                }
                break;

              case 2:
                yakflag = 0;
                yakflag = sanankoflag(yakflag);
                std::cout << "三暗刻フラグ" << yakflag << std::endl;

                switch (yakflag) {
                case 1:
                  yk[6] = sananko;
                  yak = yakadd(yak, 2);

                  yakflag = 0;
                  yakflag = sankantuflag(yakflag);
                  std::cout << "三槓子フラグ" << yakflag << std::endl;

                  switch (yakflag) {
                  case 1:
                    yk[8] = sankantu;
                    yak = yakadd(yak, 2);
                  case 2:
                  case 3:
                  
                    haiteichose(yk,yak,tumoflag,rinflag);
                    break;
                  }

                  break;

                case 2:
                  yakflag = 0;
                  yakflag = ipekoflag(yakflag);
                  std::cout << "一盃口フラグ" << yakflag << std::endl;

                  switch (yakflag) {
                  case 1:
                    yk[6] = ipeko;
                    yak = yakadd(yak, 1);

                  case 2:
                  case 3:
                  
                    haiteichose(yk,yak,tumoflag,rinflag);
                    break;
                  }
                  break;

                case 3:
                  
                  haiteichose(yk,yak,tumoflag,rinflag);
                  break;
                }
                break;

              case 3:
                
                haiteichose(yk,yak,tumoflag,rinflag);
                break;
              }
              break;

            case 2:
              yakflag = 0;
              yakflag = honituflag(yakflag);
              std::cout << "混一色フラグ" << yakflag << std::endl;

              switch (yakflag) {
              case 1:
                yk[4] = honitu;
                yak = yakadd(yak, 3);

                case 2:

                yakflag = 0;
                yakflag = ryanpekoflag(yakflag);
                std::cout << "二盃口" << yakflag << std::endl;

                switch (yakflag) {
                case 1:
                  yk[6] = ryanpeko;
                  yak = yakadd(yak, 3);

                  
                  haiteichose(yk,yak,tumoflag,rinflag);
                  break;

                case 2:
                  yakflag = 0;
                  yakflag = toitoiflag(yakflag);
                  std::cout << "対々和フラグ" << yakflag << std::endl;

                  switch (yakflag) {
                  // 対々和有
                  case 1:
                    if (tumoflag == 1) {
                      yk[0] = suanko;
                      yakumanoutput(yk);
                    } else {
                      yk[5] = toitoi;
                      yk[6] = sananko;
                      yak = yakadd(yak, 4);

                      yakflag = 0;
                      yakflag = konrotoflag(yakflag);

                      switch (yakflag) {
                      case 1:
                        yk[7] = konroto;
                        yak = yakadd(yak, 2);
                        yakflag = 0;
                        yakflag = shosangenflag(yakflag);

                        switch (yakflag) {
                        case 1:
                          yk[8] = shosangen;
                          yk[9] = sangen;
                          yk[10] = sangen;
                          yak = yakadd(yak, 4);
                        case 2:
                          yakflag = 0;
                          yakflag = kazehaiflag(oyaflag);

                          if (yakflag == 1) {
                            yk[11] = jikaze;
                            yak = yakadd(yak, 1);
                          } else if (yakflag == 2) {
                            yk[11] = bakaze;
                            yak = yakadd(yak, 1);
                          } else if (yak == 3) {
                            yk[11] = jikaze;
                            yk[12] = bakaze;
                            yak = yakadd(yak, 2);
                          }

                          
                          haiteichose(yk,yak,tumoflag,rinflag);
                          break;

                        case 3:
                       
                          haiteichose(yk,yak,tumoflag,rinflag);
                          break;
                        }
                        break;

                      case 2:
                        yakflag = 0;
                        yakflag = shosangenflag(yakflag);

                        switch (yakflag) {
                        case 1:
                          yk[8] = shosangen;
                          yk[9] = sangen;
                          yk[10] = sangen;
                          yak = yakadd(yak, 4);
                        case 2:
                          yakflag = 0;
                          yakflag = kazehaiflag(oyaflag);

                          if (yakflag == 1) {
                            yk[11] = jikaze;
                            yak = yakadd(yak, 1);
                          } else if (yakflag == 2) {
                            yk[11] = bakaze;
                            yak = yakadd(yak, 1);
                          } else if (yak == 3) {
                            yk[11] = jikaze;
                            yk[12] = bakaze;
                            yak = yakadd(yak, 2);
                          }

                          
                          haiteichose(yk,yak,tumoflag,rinflag);
                          break;

                        case 3:
                         
                          haiteichose(yk,yak,tumoflag,rinflag);
                          break;
                        }
                        break;

                      case 3:
                      
                        haiteichose(yk,yak,tumoflag,rinflag);
                        break;
                      }
                    }
                    break;

                    // 対々和無

                  case 2:
                    yakflag = 0;
                    yakflag = sanankoflag(yakflag);
                    std::cout<<"三暗刻フラグ"<<yakflag<<std::endl;

                    switch (yakflag) {
                    //三暗刻有
                    case 1:
                      yk[5] = sananko;
                      yak = yakadd(yak, 2);

                      yakflag = 0;
                      yakflag = sankantuflag(yakflag);
                      std::cout<<"三槓子フラグ"<<yakflag<<std::endl;

                      switch (yakflag) {
                      //三槓子有
                      case 1:
                        yk[6] = sankantu;
                        yak = yakadd(yak, 2);
                      //三槓子無
                      case 2:
                        yakflag = 0;
                        yakflag = tyantaflag(yakflag);
                        std::cout<<"チャンタフラグ"<<yakflag<<std::endl;

                        switch (yakflag) {
                        //チャンタ有
                        case 1:
                          yk[7] = tyanta;
                          yak = yakadd(yak, 2);
                        //チャンタ無
                        case 2:
                          yakflag = 0;
                          yakflag = shosangenflag(yakflag);
                          std::cout<<"小三元フラグ"<<yakflag<<std::endl;

                          switch (yakflag) {
                            //小三元有
                            case 1:
                            yk[8]=shosangen;
                            yk[9]=sangen;
                            yk[10]=sangen;
                            yak = yakadd(yak,4);

                            hakuflag=sangenhai();
                            if(hakuflag==1){
                              tyunflag=sangenhai();

                              if(tyunflag==0){
                                hatuflag=1;
                              }
                            }else if(hakuflag==0){
                              tyunflag=1;
                              hatuflag=1;
                            }

                            yakflag=0;
                            yakflag=kazehaiflag(oyaflag);
                            std::cout<<"風牌フラグ"<<yakflag<<std::endl;

                            switch (yakflag) {
                              case 1:
                              yk[11]=jikaze;
                              yak=yakadd(yak,1);

                              haiteichose(yk,yak,tumoflag,rinflag);
                              break;

                              case 2:
                              yk[11]=bakaze;
                              yak=yakadd(yak,1);

                              haiteichose(yk,yak,tumoflag,rinflag);

                              break;

                              case 3:
                                yk[11]=jikaze;
                                yk[12]=bakaze;
                                yak=yakadd(yak,2);

                                haiteichose(yk,yak,tumoflag,rinflag);

                              break;

                              case 4:
                                haiteichose(yk,yak,tumoflag,rinflag);
                              break;
                            
                            }
                            break;

                            case 2:
                            yakflag=0;
                            yakflag=sangenflag(yakflag);
                            std::cout<<"三元牌フラグ"<<yakflag<<std::endl;

                            switch (yakflag) {
                              case 1:
                              case 2:
                              case 3:

                                if(yakflag==1){
                                  hakuflag=1;
                                }else if(yakflag==2){
                                  hatuflag=1;
                                }else if(yakflag==3){
                                  tyunflag=1;
                                }
                                yk[8]=sangen;
                                yak=yakadd(yak, 1);

                                yakflag=0;
                                yakflag=sangenflag(yakflag);
                                std::cout<<"三元牌フラグ"<<yakflag<<std::endl;

                                switch (yakflag) {
                                  case 1:
                                  case 2:
                                  case 3:

                                    if(yakflag==1){
                                      if(hakuflag==1){
                                        hatuflag=sangenhai();
                                        if(hatuflag==0){
                                          tyunflag=1;
                                        }
                                      }else{
                                        hakuflag=1;
                                      }
                                    }else if(yakflag==2){
                                      if(hatuflag==1){
                                        tyunflag=sangenhai();
                                        if(tyunflag==0){
                                          hakuflag=1;
                                        }
                                      }else{
                                        hatuflag=1;
                                      }

                                    }else if(yakflag==3){
                                      if(tyunflag==1){
                                        hakuflag=sangenhai();
                                        if(hakuflag==0){
                                          hatuflag=1;
                                        }
                                      }else {
                                        tyunflag=1;
                                      }

                                    }

                                    yk[9]=sangen;
                                    yak=yakadd(yak,1);

                                    yakflag=0;
                                    yakflag=kazehaiflag(oyaflag);
                                    std::cout<<"風牌フラグ"<<yakflag<<std::endl;

                                    switch (yakflag) {
                                      case 1:
                                        yk[10]=jikaze;
                                        yak=yakadd(yak, 1);

                                        haiteichose(yk,yak,tumoflag,rinflag);
                                      break;

                                      case 2:
                                        yk[10]=bakaze;
                                        yak=yakadd(yak, 1);

                                        haiteichose(yk,yak,tumoflag,rinflag);
                                      break;

                                      case 3:
                                      yk[10]=jikaze;
                                      yk[11]=bakaze;
                                      yak=yakadd(yak,2);

                                      haiteichose(yk,yak,tumoflag,rinflag);
                                      break;

                                      case 4:
                                        haiteichose(yk,yak,tumoflag,rinflag);
                                      break;
                                    }
                                  break;
                                
                                }

                              break;

                              case 4:
                                yakflag=0;
                                yakflag=kazehaiflag(oyaflag);
                                std::cout<<"風牌フラグ"<<yakflag<<std::endl;

                                switch (yakflag) {
                                  case 1:
                                    yk[8]=jikaze;
                                    yak=yakadd(yak, 1);

                                    yakflag=0;
                                    yakflag=kazehaiflag(oyaflag);
                                    std::cout<<"風牌フラグ"<<yakflag<<std::endl;

                                    switch (yakflag) {
                                      case 2:
                                        yk[9]=bakaze;
                                        yak=yakadd(yak, 1);
                                      case 1:
                                      case 3:
                                      case 4:
                                        yakflag=kazehaiflag(oyaflag);
                                      break;
                                    
                                    }
                                  break;
                                  
                                  case 2:
                                    yk[8]=bakaze;
                                    yak=yakadd(yak, 1);

                                    yakflag=0;
                                    yakflag=kazehaiflag(oyaflag);
                                    std::cout<<"風牌フラグ"<<yakflag<<std::endl;

                                    switch (yakflag) {
                                      case 1:
                                        yk[9]=jikaze;
                                        yak=yakadd(yak, 1);
                                      case 2:
                                      case 3:
                                      case 4:
                                        yakflag=kazehaiflag(oyaflag);
                                      break;
                                    
                                    }
                                    
                                  break;

                                  case 3:
                                    yk[8]=jikaze;
                                    yk[9]=bakaze;
                                    yak=yakadd(yak, 2);

                                    haiteichose(yk,yak,tumoflag,rinflag);
                                  break;

                                  case 4:
                                    haiteichose(yk,yak,tumoflag,rinflag);
                                  break;
                                
                                }
                              break;
                            
                            }
                            
                            break;
                          }


                          //ここからつづき

                          break;

                        case 3:
                          haiteichose(yk,yak,tumoflag,rinflag);
                        break;
                        }
                        break;
                      }
                      break;
                    //三暗刻無
                    case 2:
                      yakflag = 0;
                      yakflag = shosangenflag(yakflag);
                      std::cout<<"小三元フラグ"<<yakflag<<std::endl;

                      switch (yakflag) {
                      case 1:
                        yk[5] = shosangen;
                        yk[6] = sangen;
                        yk[7] = sangen;
                        yak = yakadd(yak, 4);

                        yakflag = 0;
                        yakflag = tyantaflag(yakflag);

                        switch (yakflag) {
                        case 1:
                          yk[9] = tyanta;
                          yak = yakadd(yak, 2);

                          yakflag = 0;
                          yakflag = ipekoflag(yakflag);

                          switch (yakflag) {
                          case 1:
                            yk[10] = ipeko;
                            yak = yakadd(yak, 1);
                          case 2:
                            yakflag = 0;
                            yakflag = kazehaiflag(oyaflag);

                            switch (yakflag) {
                            case 1:
                              yk[11] = jikaze;
                              yak = yakadd(yak, 1);

                              
                              haiteichose(yk,yak,tumoflag,rinflag);
                              break;

                            case 2:
                              yk[11] = bakaze;
                              yak = yakadd(yak, 1);

                            
                              haiteichose(yk,yak,tumoflag,rinflag);
                              break;

                            case 3:
                              yk[11] = jikaze;
                              yk[12] = bakaze;
                              yak = yakadd(yak, 2);

                              
                              haiteichose(yk,yak,tumoflag,rinflag);
                              break;

                            case 4:
                             
                              haiteichose(yk,yak,tumoflag,rinflag);
                              break;
                            }

                            break;

                          case 3:
                            
                            haiteichose(yk,yak,tumoflag,rinflag);
                            break;
                          }
                          break;

                        case 2:
                          yakflag = 0;
                          yakflag = ipekoflag(yakflag);

                          switch (yakflag) {
                          case 1:
                            yk[10] = ipeko;
                            yak = yakadd(yak, 1);
                          case 2:
                            yakflag = 0;
                            yakflag = kazehaiflag(oyaflag);

                            switch (yakflag) {
                            case 1:
                              yk[11] = jikaze;
                              yak = yakadd(yak, 1);

                             
                              haiteichose(yk,yak,tumoflag,rinflag);
                              break;

                            case 2:
                              yk[11] = bakaze;
                              yak = yakadd(yak, 1);

                              
                              haiteichose(yk,yak,tumoflag,rinflag);
                              break;

                            case 3:
                              yk[11] = jikaze;
                              yk[12] = bakaze;
                              yak = yakadd(yak, 2);

                              
                              haiteichose(yk,yak,tumoflag,rinflag);
                              break;

                            case 4:
                             
                              haiteichose(yk,yak,tumoflag,rinflag);
                              break;
                            }

                            break;

                          case 3:
                           
                            haiteichose(yk,yak,tumoflag,rinflag);
                            break;
                          }
                          break;

                        case 3:
                         
                          haiteichose(yk,yak,tumoflag,rinflag);
                          break;
                        }
                        break;

                      case 2:
                        yakflag = 0;
                        yakflag = tyantaflag(yakflag);
                        std::cout<<"チャンタフラグ"<<yakflag<<std::endl;

                        switch (yakflag) {
                        // チャンタ有
                        case 1:
                          yk[5] = tyanta;
                          yak = yakadd(yak, 2);

                          yakflag = 0;
                          yakflag = ipekoflag(yakflag);

                          switch (yakflag) {
                          case 1:
                            yk[6] = ipeko;
                            yak = yakadd(yak, 1);

                            yakflag = 0;
                            yakflag = kazehaiflag(oyaflag);

                            switch (yakflag) {
                            case 1:
                              yk[7] = jikaze;
                              yak = yakadd(yak, 1);

                              yakflag = 0;
                              yakflag = sangenflag(yakflag);

                              switch (yakflag) {
                              case 1:
                              case 2:
                              case 3:
                                yk[8] = sangen;
                                yak = yakadd(yak, 1);

                                if ((yakflag == 1) && (hakuflag == 0)) {
                                  hakuflag = 1;
                                } else if ((yakflag == 2) && (hatuflag == 0)) {
                                  hatuflag = 1;
                                } else if ((yakflag == 3) && (tyunflag == 0)) {
                                  tyunflag = 1;
                                }

                               
                                haiteichose(yk,yak,tumoflag,rinflag);
                                break;

                              case 4:
                                
                                haiteichose(yk,yak,tumoflag,rinflag);
                                break;
                              }
                              break;

                            case 2:
                              yk[7] = bakaze;
                              yak = yakadd(yak, 1);

                              yakflag = 0;
                              yakflag = sangenflag(yakflag);

                              switch (yakflag) {
                              case 1:
                              case 2:
                              case 3:
                                yk[8] = sangen;
                                yak = yakadd(yak, 1);

                                if ((yakflag == 1) && (hakuflag == 0)) {
                                  hakuflag = 1;
                                } else if ((yakflag == 2) && (hatuflag == 0)) {
                                  hatuflag = 1;
                                } else if ((yakflag == 3) && (tyunflag == 0)) {
                                  tyunflag = 1;
                                }

                             
                                haiteichose(yk,yak,tumoflag,rinflag);
                                break;

                              case 4:
                             
                                haiteichose(yk,yak,tumoflag,rinflag);
                                break;
                              }
                              break;

                            case 3:
                              yk[7] = jikaze;
                              yk[8] = bakaze;
                              yak = yakadd(yak, 2);

                              yakflag = 0;
                              yakflag = sangenflag(yakflag);

                              switch (yakflag) {
                              case 1:
                              case 2:
                              case 3:
                                yk[9] = sangen;
                                yak = yakadd(yak, 1);

                                if ((yakflag == 1) && (hakuflag == 0)) {
                                  hakuflag = 1;
                                } else if ((yakflag == 2) && (hatuflag == 0)) {
                                  hatuflag = 1;
                                } else if ((yakflag == 3) && (tyunflag == 0)) {
                                  tyunflag = 1;
                                }

                              
                                haiteichose(yk,yak,tumoflag,rinflag);
                                break;

                              case 4:
                                
                                haiteichose(yk,yak,tumoflag,rinflag);
                                break;
                              }
                              break;

                            case 4:
                              yakflag = 0;
                              yakflag = sangenflag(yakflag);

                              switch (yakflag) {
                              case 1:
                              case 2:
                              case 3:
                                yk[7] = sangen;
                                yak = yakadd(yak, 1);

                                if (yakflag == 1) {
                                  hakuflag = 1;
                                } else if (yakflag == 2) {
                                  hatuflag = 1;
                                } else if (yakflag == 3) {
                                  tyunflag = 1;
                                }
                                yakflag = 0;
                                yakflag = sangenflag(yakflag);

                                switch (yakflag) {
                                case 1:
                                case 2:
                                case 3:
                                  yk[8] = sangen;
                                  yak = yakadd(yak, 1);

                                  if ((yakflag == 1) && (hakuflag == 0)) {
                                    hakuflag = 1;
                                  } else if ((yakflag == 2) &&
                                             (hatuflag == 0)) {
                                    hatuflag = 1;
                                  } else if ((yakflag == 3) &&
                                             (tyunflag == 0)) {
                                    tyunflag = 1;
                                  }

                                 
                                  haiteichose(yk,yak,tumoflag,rinflag);

                                  break;

                                case 4:
                                  
                                  haiteichose(yk,yak,tumoflag,rinflag);
                                  break;
                                }

                                break;

                              case 4:
                               
                                haiteichose(yk,yak,tumoflag,rinflag);
                                break;
                              }
                              break;
                            }
                            break;

                          case 2:
                            yakflag = 0;
                            yakflag = kazehaiflag(oyaflag);

                            switch (yakflag) {
                            case 1:
                              yk[6] = jikaze;
                              yak = yakadd(yak, 1);

                              yakflag = 0;
                              yakflag = kazehaiflag(oyaflag);

                              switch (yakflag) {
                              case 2:
                                yk[7] = bakaze;
                                yak = yakadd(yak, 1);

                                yakflag = 0;
                                yakflag = sangenflag(yakflag);

                                switch (yakflag) {
                                case 1:
                                case 2:
                                case 3:
                                  yk[8] = sangen;
                                  yak = yakadd(yak, 1);

                                  if (yakflag == 1) {
                                    hakuflag = 1;
                                  } else if (yakflag == 2) {
                                    hatuflag = 1;
                                  } else if (yakflag == 3) {
                                    tyunflag = 1;
                                  }

                                  yakflag = 0;
                                  yakflag = sangenflag(yakflag);

                                  switch (yakflag) {
                                  case 1:
                                  case 2:
                                  case 3:
                                    yk[9] = sangen;
                                    yak = yakadd(yak, 1);

                                    if ((yakflag == 1) && (hakuflag == 0)) {
                                      hakuflag = 1;
                                    } else if ((yakflag == 2) &&
                                               (hatuflag == 0)) {
                                      hatuflag = 1;
                                    } else if ((yakflag == 3) &&
                                               (tyunflag = 0)) {
                                      tyunflag = 1;
                                    }

                                    
                                    haiteichose(yk,yak,tumoflag,rinflag);
                                    break;

                                  case 4:
                                   
                                    haiteichose(yk,yak,tumoflag,rinflag);
                                    break;
                                  }
                                  break;

                                case 4:
                                 
                                  haiteichose(yk,yak,tumoflag,rinflag);
                                  break;
                                }

                                break;

                              case 1:
                              case 3:
                                yakflag = 0;
                                yakflag = sangenflag(yakflag);

                                switch (yakflag) {
                                case 1:
                                case 2:
                                case 3:
                                  yak = yakadd(yak, 1);
                                  yk[8] = sangen;

                                  if (yakflag == 1) {
                                    hakuflag = 1;
                                  } else if (yakflag == 2) {
                                    hatuflag = 1;
                                  } else if (yakflag == 3) {
                                    tyunflag = 1;
                                  }

                                  yakflag = 0;
                                  yakflag = sangenflag(yakflag);

                                  switch (yakflag) {
                                  case 1:
                                  case 2:
                                  case 3:
                                    if ((yakflag == 1) && (hakuflag == 0)) {
                                      yak = yakadd(yak, 1);
                                      yk[9] = sangen;
                                      hakuflag = 1;
                                    } else if ((yakflag == 2) &&
                                               (hatuflag == 0)) {
                                      yak = yakadd(yak, 1);
                                      yk[9] = sangen;
                                      hatuflag = 1;
                                    } else if ((yakflag == 3) &&
                                               (tyunflag == 0)) {
                                      yak = yakadd(yak, 1);
                                      tyunflag = 1;
                                    }

                                   
                                    haiteichose(yk,yak,tumoflag,rinflag);
                                    break;

                                  case 4:
                                    
                                    haiteichose(yk,yak,tumoflag,rinflag);
                                    break;
                                  }

                                  break;
                                }
                                break;

                              case 4:
                                
                                haiteichose(yk,yak,tumoflag,rinflag);
                                break;
                              }
                              break;

                            case 2:
                              yk[6] = bakaze;
                              yak = yakadd(yak, 1);

                              yakflag = 0;
                              yakflag = kazehaiflag(oyaflag);

                              switch (yakflag) {
                              case 1:
                                yk[7] = jikaze;
                                yak = yakadd(yak, 1);

                                yakflag = 0;
                                yakflag = sangenflag(yakflag);

                                switch (yakflag) {
                                case 1:
                                case 2:
                                case 3:
                                  yk[8] = sangen;
                                  yak = yakadd(yak, 1);

                                  if (yakflag == 1) {
                                    hakuflag = 1;
                                  } else if (yakflag == 2) {
                                    hatuflag = 1;
                                  } else if (yakflag == 3) {
                                    tyunflag = 1;
                                  }

                                  yakflag = 0;
                                  yakflag = sangenflag(yakflag);

                                  switch (yakflag) {
                                  case 1:
                                  case 2:
                                  case 3:
                                    yk[9] = sangen;
                                    yak = yakadd(yak, 1);

                                    if ((yakflag == 1) && (hakuflag == 0)) {
                                      hakuflag = 1;
                                    } else if ((yakflag == 2) &&
                                               (hatuflag == 0)) {
                                      hatuflag = 1;
                                    } else if ((yakflag == 3) &&
                                               (tyunflag = 0)) {
                                      tyunflag = 1;
                                    }

                                    haiteichose(yk,yak,tumoflag,rinflag);

                                    break;

                                  case 4:
                                   
                                    haiteichose(yk,yak,tumoflag,rinflag);
                                    break;
                                  }
                                  break;

                                case 4:
                                  
                                  haiteichose(yk,yak,tumoflag,rinflag);
                                  break;
                                }

                                break;

                              case 2:
                              case 3:
                                yakflag = 0;
                                yakflag = sangenflag(yakflag);

                                switch (yakflag) {
                                case 1:
                                case 2:
                                case 3:
                                  yak = yakadd(yak, 1);
                                  yk[7] = sangen;

                                  if (yakflag == 1) {
                                    hakuflag = 1;
                                  } else if (yakflag == 2) {
                                    hatuflag = 1;
                                  } else if (yakflag == 3) {
                                    tyunflag = 1;
                                  }

                                  yakflag = 0;
                                  yakflag = sangenflag(yakflag);

                                  switch (yakflag) {
                                  case 1:
                                  case 2:
                                  case 3:
                                    if ((yakflag == 1) && (hakuflag == 0)) {
                                      yak = yakadd(yak, 1);
                                      yk[8] = sangen;
                                      hakuflag = 1;
                                    } else if ((yakflag == 2) &&
                                               (hatuflag == 0)) {
                                      yak = yakadd(yak, 1);
                                      yk[8] = sangen;
                                      hatuflag = 1;
                                    } else if ((yakflag == 3) &&
                                               (tyunflag == 0)) {
                                      yak = yakadd(yak, 1);
                                      tyunflag = 1;
                                    }

                                    
                                    haiteichose(yk,yak,tumoflag,rinflag);
                                    break;

                                  case 4:
                                    
                                    haiteichose(yk,yak,tumoflag,rinflag);
                                    break;
                                  }

                                  break;
                                }
                                break;

                              case 4:
                                
                                haiteichose(yk,yak,tumoflag,rinflag);
                                break;
                              }
                              break;

                            case 3:
                              yk[6] = jikaze;
                              yk[7] = bakaze;
                              yak = yakadd(yak, 2);

                              yakflag = 0;
                              yakflag = sangenflag(yakflag);

                              switch (yakflag) {
                              case 1:
                              case 2:
                              case 3:
                                yk[8] = sangen;
                                yak = yakadd(yak, 1);
                                if (yakflag == 1) {
                                  hakuflag = 1;
                                } else if (yakflag == 2) {
                                  hatuflag = 1;
                                } else if (yakflag == 3) {
                                  tyunflag = 1;
                                }

                                yakflag = 0;
                                yakflag = sangenflag(yakflag);

                                switch (yakflag) {
                                case 1:
                                case 2:
                                case 3:
                                  if ((yakflag == 1) && (hakuflag == 0)) {
                                    yk[9] = sangen;
                                    yak = yakadd(yak, 1);
                                    hakuflag = 1;
                                  } else if ((yakflag == 2) &&
                                             (hatuflag == 0)) {
                                    yk[9] = sangen;
                                    yak = yakadd(yak, 1);
                                    hatuflag = 1;
                                  } else if ((yakflag == 3) &&
                                             (tyunflag == 0)) {
                                    yk[9] = sangen;
                                    yak = yakadd(yak, 1);
                                    tyunflag = 1;
                                  }
                                case 4:
                                 
                                  haiteichose(yk,yak,tumoflag,rinflag);

                                  break;
                                }
                                break;

                              case 4:
                                
                                haiteichose(yk,yak,tumoflag,rinflag);
                                break;
                              }
                              break;

                            case 4:
                             
                              haiteichose(yk,yak,tumoflag,rinflag);

                              break;
                            }

                          case 3:
                            
                            haiteichose(yk,yak,tumoflag,rinflag);
                            break;
                          }
                          break;

                        // チャンタ無
                        case 2:
                          yakflag = 0;
                          yakflag = ittuflag(yakflag);
                          std::cout<<"一気通貫フラグ"<<yakflag<<std::endl;

                          switch (yakflag) {
                          case 1:
                            yk[5] = ittu;
                            yak = yakadd(yak, 2);

                            yakflag = 0;
                            yakflag = ipekoflag(yakflag);

                            switch (yakflag) {
                            case 1:
                              yk[6] = ipeko;
                              yak = yakadd(yak, 1);

                              
                              haiteichose(yk,yak,tumoflag,rinflag);

                              break;

                            case 2:
                              yakflag = 0;
                              yakflag = kazehaiflag(oyaflag);

                              switch (yakflag) {
                              case 1:
                              case 2:
                              case 3:
                                if (yakflag == 1) {
                                  yk[6] = jikaze;
                                  yak = yakadd(yak, 1);
                                } else if (yakflag == 2) {
                                  yk[6] = bakaze;
                                  yak = yakadd(yak, 1);
                                } else if (yakflag == 3) {
                                  yk[6] = jikaze;
                                  yk[7] = bakaze;
                                  yak = yakadd(yak, 2);
                                }

                               
                                haiteichose(yk,yak,tumoflag,rinflag);
                                break;

                              case 4:
                                yakflag = 0;
                                yakflag = sangenflag(yakflag);

                                switch (yakflag) {
                                case 1:
                                case 2:
                                case 3:
                                  yk[6] = sangen;
                                  yak = yakadd(yak, 1);

                                  if (yakflag == 1) {
                                    hakuflag = 1;
                                  } else if (yakflag == 2) {
                                    hatuflag = 1;
                                  } else if (yakflag == 3) {
                                    tyunflag = 1;
                                  }
                                  
                                  haiteichose(yk,yak,tumoflag,rinflag);

                                  break;

                                case 4:
                                 
                                  haiteichose(yk,yak,tumoflag,rinflag);
                                  break;
                                }
                                break;
                              }
                              break;

                            case 3:
                              
                              haiteichose(yk,yak,tumoflag,rinflag);
                              break;
                            }
                            break;

                          case 2:
                            yakflag = 0;
                            yakflag = ipekoflag(yakflag);
                            std::cout<<"一盃口フラグ"<<yakflag<<std::endl;

                            switch (yakflag) {
                            case 1:
                              yk[5] = ipeko;
                              yak = yakadd(yak, 1);

                              yakflag = 0;
                              yakflag = kazehaiflag(oyaflag);

                              switch (yakflag) {
                              case 1:
                                yk[6] = jikaze;
                                yak = yakadd(yak, 1);

                                yakflag = 0;
                                yakflag = sangenflag(yakflag);

                                switch (yakflag) {
                                case 1:
                                case 2:
                                case 3:
                                  yk[7] = sangen;
                                  yak = yakadd(yak, 1);

                                  if ((yakflag == 1) && (hakuflag == 0)) {
                                    hakuflag = 1;
                                  } else if ((yakflag == 2) &&
                                             (hatuflag == 0)) {
                                    hatuflag = 1;
                                  } else if ((yakflag == 3) &&
                                             (tyunflag == 0)) {
                                    tyunflag = 1;
                                  }

                                  
                                  haiteichose(yk,yak,tumoflag,rinflag);
                                  break;

                                case 4:
                                
                                  haiteichose(yk,yak,tumoflag,rinflag);
                                  break;
                                }
                                break;

                              case 2:
                                yk[6] = bakaze;
                                yak = yakadd(yak, 1);

                                yakflag = 0;
                                yakflag = sangenflag(yakflag);

                                switch (yakflag) {
                                case 1:
                                case 2:
                                case 3:
                                  yk[7] = sangen;
                                  yak = yakadd(yak, 1);

                                  if ((yakflag == 1) && (hakuflag == 0)) {
                                    hakuflag = 1;
                                  } else if ((yakflag == 2) &&
                                             (hatuflag == 0)) {
                                    hatuflag = 1;
                                  } else if ((yakflag == 3) &&
                                             (tyunflag == 0)) {
                                    tyunflag = 1;
                                  }

                                 
                                  haiteichose(yk,yak,tumoflag,rinflag);
                                  break;

                                case 4:
                                  
                                  haiteichose(yk,yak,tumoflag,rinflag);
                                  break;
                                }
                                break;

                              case 3:
                                yk[6] = jikaze;
                                yk[7] = bakaze;
                                yak = yakadd(yak, 2);

                                yakflag = 0;
                                yakflag = sangenflag(yakflag);

                                switch (yakflag) {
                                case 1:
                                case 2:
                                case 3:
                                  yk[9] = sangen;
                                  yak = yakadd(yak, 1);

                                  if ((yakflag == 1) && (hakuflag == 0)) {
                                    hakuflag = 1;
                                  } else if ((yakflag == 2) &&
                                             (hatuflag == 0)) {
                                    hatuflag = 1;
                                  } else if ((yakflag == 3) &&
                                             (tyunflag == 0)) {
                                    tyunflag = 1;
                                  }

                               
                                  haiteichose(yk,yak,tumoflag,rinflag);
                                  break;

                                case 4:
                               
                                  haiteichose(yk,yak,tumoflag,rinflag);
                                  break;
                                }
                                break;

                              case 4:
                                yakflag = 0;
                                yakflag = sangenflag(yakflag);

                                switch (yakflag) {
                                case 1:
                                case 2:
                                case 3:
                                  yk[6] = sangen;
                                  yak = yakadd(yak, 1);

                                  if (yakflag == 1) {
                                    hakuflag = 1;
                                  } else if (yakflag == 2) {
                                    hatuflag = 1;
                                  } else if (yakflag == 3) {
                                    tyunflag = 1;
                                  }
                                  yakflag = 0;
                                  yakflag = sangenflag(yakflag);

                                  switch (yakflag) {
                                  case 1:
                                  case 2:
                                  case 3:
                                    yk[7] = sangen;
                                    yak = yakadd(yak, 1);

                                    if ((yakflag == 1) && (hakuflag == 0)) {
                                      hakuflag = 1;
                                    } else if ((yakflag == 2) &&
                                               (hatuflag == 0)) {
                                      hatuflag = 1;
                                    } else if ((yakflag == 3) &&
                                               (tyunflag == 0)) {
                                      tyunflag = 1;
                                    }

                                   
                                    haiteichose(yk,yak,tumoflag,rinflag);

                                    break;

                                  case 4:
                                   
                                    haiteichose(yk,yak,tumoflag,rinflag);
                                    break;
                                  }

                                  break;

                                case 4:
                                 
                                  haiteichose(yk,yak,tumoflag,rinflag);
                                  break;
                                }
                                break;
                              }
                              break;

                            case 2:
                              yakflag = 0;
                              yakflag = kazehaiflag(oyaflag);
                              std::cout<<"風牌フラグ"<<yakflag<<std::endl;

                              switch (yakflag) {
                              case 1:
                                yk[5] = jikaze;
                                yak = yakadd(yak, 1);

                                yakflag = 0;
                                yakflag = kazehaiflag(oyaflag);
                                std::cout<<"風牌フラグ"<<yakflag<<std::endl;

                                switch (yakflag) {
                                case 2:
                                  yk[6] = bakaze;
                                  yak = yakadd(yak, 1);

                                  yakflag = 0;
                                  yakflag = sangenflag(yakflag);
                                  std::cout<<"三元牌フラグ"<<yakflag<<std::endl;

                                  switch (yakflag) {
                                  case 1:
                                  case 2:
                                  case 3:
                                    yk[7] = sangen;
                                    yak = yakadd(yak, 1);

                                    if (yakflag == 1) {
                                      hakuflag = 1;
                                    } else if (yakflag == 2) {
                                      hatuflag = 1;
                                    } else if (yakflag == 3) {
                                      tyunflag = 1;
                                    }

                                    yakflag = 0;
                                    yakflag = sangenflag(yakflag);
                                    std::cout<<"三元牌フラグ"<<yakflag<<std::endl;

                                    switch (yakflag) {
                                    case 1:
                                    case 2:
                                    case 3:
                                      yk[8] = sangen;
                                      yak = yakadd(yak, 1);

                                      if ((yakflag == 1) && (hakuflag == 0)) {
                                        hakuflag = 1;
                                      } else if ((yakflag == 2) &&
                                                 (hatuflag == 0)) {
                                        hatuflag = 1;
                                      } else if ((yakflag == 3) &&
                                                 (tyunflag = 0)) {
                                        tyunflag = 1;
                                      }

                                      
                                      haiteichose(yk,yak,tumoflag,rinflag);
                                      break;

                                    case 4:
                                      
                                      haiteichose(yk,yak,tumoflag,rinflag);
                                      break;
                                    }
                                    break;

                                  case 4:
                                    
                                    haiteichose(yk,yak,tumoflag,rinflag);
                                    break;
                                  }

                                  break;

                                case 1:
                                case 3:
                                  yakflag = 0;
                                  yakflag = sangenflag(yakflag);
                                  std::cout<<"三元牌フラグ"<<yakflag<<std::endl;

                                  switch (yakflag) {
                                  case 1:
                                  case 2:
                                  case 3:
                                    yak = yakadd(yak, 1);
                                    yk[7] = sangen;

                                    if (yakflag == 1) {
                                      hakuflag = 1;
                                    } else if (yakflag == 2) {
                                      hatuflag = 1;
                                    } else if (yakflag == 3) {
                                      tyunflag = 1;
                                    }

                                    yakflag = 0;
                                    yakflag = sangenflag(yakflag);
                                    std::cout<<"三元牌フラグ"<<yakflag<<std::endl;

                                    switch (yakflag) {
                                    case 1:
                                    case 2:
                                    case 3:
                                      if ((yakflag == 1) && (hakuflag == 0)) {
                                        yak = yakadd(yak, 1);
                                        yk[8] = sangen;
                                        hakuflag = 1;
                                      } else if ((yakflag == 2) &&
                                                 (hatuflag == 0)) {
                                        yak = yakadd(yak, 1);
                                        yk[8] = sangen;
                                        hatuflag = 1;
                                      } else if ((yakflag == 3) &&
                                                 (tyunflag == 0)) {
                                        yak = yakadd(yak, 1);
                                        tyunflag = 1;
                                      }

                                      haiteichose(yk,yak,tumoflag,rinflag);
                                      break;

                                    case 4:
                                    
                                      haiteichose(yk,yak,tumoflag,rinflag);
                                      break;
                                    }

                                    break;
                                  }
                                  break;

                                case 4:
                                  
                                  haiteichose(yk,yak,tumoflag,rinflag);
                                  break;
                                }
                                break;

                              case 2:
                                yk[5] = bakaze;
                                yak = yakadd(yak, 1);

                                yakflag = 0;
                                yakflag = kazehaiflag(oyaflag);
                                std::cout<<"風牌フラグ"<<yakflag<<std::endl;

                                switch (yakflag) {
                                case 1:
                                  yk[6] = jikaze;
                                  yak = yakadd(yak, 1);

                                  yakflag = 0;
                                  yakflag = sangenflag(yakflag);
                                  std::cout<<"三元牌フラグ"<<yakflag<<std::endl;

                                  switch (yakflag) {
                                  case 1:
                                  case 2:
                                  case 3:
                                    yk[7] = sangen;
                                    yak = yakadd(yak, 1);

                                    if (yakflag == 1) {
                                      hakuflag = 1;
                                    } else if (yakflag == 2) {
                                      hatuflag = 1;
                                    } else if (yakflag == 3) {
                                      tyunflag = 1;
                                    }

                                    yakflag = 0;
                                    yakflag = sangenflag(yakflag);

                                    switch (yakflag) {
                                    case 1:
                                    case 2:
                                    case 3:
                                      yk[8] = sangen;
                                      yak = yakadd(yak, 1);

                                      if ((yakflag == 1) && (hakuflag == 0)) {
                                        hakuflag = 1;
                                      } else if ((yakflag == 2) &&
                                                 (hatuflag == 0)) {
                                        hatuflag = 1;
                                      } else if ((yakflag == 3) &&
                                                 (tyunflag = 0)) {
                                        tyunflag = 1;
                                      }

                                      yakflag = 0;
                                      yakflag = sangenflag(yakflag);
                                      break;

                                    case 4:
                                      
                                      haiteichose(yk,yak,tumoflag,rinflag);
                                      break;
                                    }
                                    break;

                                  case 4:
                                    
                                    haiteichose(yk,yak,tumoflag,rinflag);
                                    break;
                                  }

                                  break;

                                case 2:
                                case 3:
                                  yakflag = 0;
                                  yakflag = sangenflag(yakflag);
                                  std::cout<<"三元牌フラグ"<<yakflag<<std::endl;

                                  switch (yakflag) {
                                  case 1:
                                  case 2:
                                  case 3:
                                    yak = yakadd(yak, 1);
                                    yk[7] = sangen;

                                    if (yakflag == 1) {
                                      hakuflag = 1;
                                    } else if (yakflag == 2) {
                                      hatuflag = 1;
                                    } else if (yakflag == 3) {
                                      tyunflag = 1;
                                    }

                                    yakflag = 0;
                                    yakflag = sangenflag(yakflag);
                                    std::cout<<"三元牌フラグ"<<yakflag<<std::endl;

                                    switch (yakflag) {
                                    case 1:
                                    case 2:
                                    case 3:
                                      if ((yakflag == 1) && (hakuflag == 0)) {
                                        yak = yakadd(yak, 1);
                                        yk[8] = sangen;
                                        hakuflag = 1;
                                      } else if ((yakflag == 2) &&
                                                 (hatuflag == 0)) {
                                        yak = yakadd(yak, 1);
                                        yk[8] = sangen;
                                        hatuflag = 1;
                                      } else if ((yakflag == 3) &&
                                                 (tyunflag == 0)) {
                                        yak = yakadd(yak, 1);
                                        tyunflag = 1;
                                      }

                                      
                                      haiteichose(yk,yak,tumoflag,rinflag);
                                      break;

                                    case 4:
                                     
                                      haiteichose(yk,yak,tumoflag,rinflag);
                                      break;
                                    }

                                    break;
                                  }
                                  break;

                                case 4:
                                 
                                  haiteichose(yk,yak,tumoflag,rinflag);
                                  break;
                                }
                                break;

                              case 3:
                                yk[6] = jikaze;
                                yk[7] = bakaze;
                                yak = yakadd(yak, 2);

                                yakflag = 0;
                                yakflag = sangenflag(yakflag);
                                std::cout<<"三元牌フラグ"<<yakflag<<std::endl;

                                switch (yakflag) {
                                case 1:
                                case 2:
                                case 3:
                                  yk[8] = sangen;
                                  yak = yakadd(yak, 1);
                                  if (yakflag == 1) {
                                    hakuflag = 1;
                                  } else if (yakflag == 2) {
                                    hatuflag = 1;
                                  } else if (yakflag == 3) {
                                    tyunflag = 1;
                                  }

                                  yakflag = 0;
                                  yakflag = sangenflag(yakflag);

                                  switch (yakflag) {
                                  case 1:
                                  case 2:
                                  case 3:
                                    if ((yakflag == 1) && (hakuflag == 0)) {
                                      yk[9] = sangen;
                                      yak = yakadd(yak, 1);
                                      hakuflag = 1;
                                    } else if ((yakflag == 2) &&
                                               (hatuflag == 0)) {
                                      yk[9] = sangen;
                                      yak = yakadd(yak, 1);
                                      hatuflag = 1;
                                    } else if ((yakflag == 3) &&
                                               (tyunflag == 0)) {
                                      yk[9] = sangen;
                                      yak = yakadd(yak, 1);
                                      tyunflag = 1;
                                    }
                                  case 4:
                                    
                                    haiteichose(yk,yak,tumoflag,rinflag);

                                    break;
                                  }
                                  break;

                                case 4:
                                 
                                  haiteichose(yk,yak,tumoflag,rinflag);
                                  break;
                                }
                                break;

                              case 4:
                                
                                haiteichose(yk,yak,tumoflag,rinflag);

                                break;
                              }
                            break;

                            case 3:
                             
                              haiteichose(yk,yak,tumoflag,rinflag);
                              break;
                            }
                            break;

                          case 3:
                           
                            haiteichose(yk,yak,tumoflag,rinflag);
                            break;
                          }
                          break;

                        case 3:
                          
                          haiteichose(yk,yak,tumoflag,rinflag);
                          break;
                        }

                        break;

                      case 3:
                       
                        haiteichose(yk,yak,tumoflag,rinflag);
                        break;
                      }
                      break;

                    case 3:
                     
                      haiteichose(yk,yak,tumoflag,rinflag);
                      break;
                    }

                    break;

                  case 3:
                   
                    haiteichose(yk,yak,tumoflag,rinflag);
                    break;
                  }
                  break;

                case 3:
                 
                  haiteichose(yk,yak,tumoflag,rinflag);
                  break;
                }
                break;

              }
              break;

            case 3:
              
              haiteichose(yk,yak,tumoflag,rinflag);
              break;
            }
            break;

          case 3:
            
            haiteichose(yk,yak,tumoflag,rinflag);
            break;
          }
          break;

        // 役決定
        case 3:
          
          haiteichose(yk,yak,tumoflag,rinflag);
          break;
        }
        break;

      // 役決定
      case 3:
        
        haiteichose(yk,yak,tumoflag,rinflag);
        break;
      }
      break;

      // 役決定

    case 3:
      if (reach == 3) {
        if (kakuritu <= 188) {
          yk[3] = tumo;
          yak = yakadd(yak, 1);
        }
      }
     
      haiteichose(yk,yak,tumoflag,rinflag);
      break;
    }
    break;
  }

  x = yak;
  return x;
}

int furo(int yk[],int yak, int oyaflag){
  int yakflag;
  int kakuritu;
  int tumoflag = 0;
  int rinflag = 0;
  int hakuflag = 0;
  int hatuflag = 0;
  int tyunflag = 0;
  int x = 0;

  // ツモの有無
  if (kakuritu <= 188) {
    yakflag = 1;
  } else {
    yakflag = 2;
  }

  std::cout << "ツモフラグ" << yakflag << std::endl;

  switch (yakflag) {

    case 1:
      tumoflag=1;
    case 2:
      yakflag=0;
      
    if (kakuritu <= 224) {
      yakflag = 1;
    } else if (kakuritu <= 900) {
      yakflag = 2;
    } else if (kakuritu > 900) {
      yakflag = 3;
    }
    std::cout << "タンヤオフラグ" << yakflag << std::endl;

    switch(yakflag){
      case 1:
      case 2:
      case 3:
      break;
    }


    break;
  
  }

  return yak;
}

//役選択プログラム
int yakchose(int naki) {
  int yakflag;
  int yk[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int kakuritu;
  int yak = 0;
  int tumoflag = 0;
  int reachflag = 0;
  int rinflag = 0;
  int oyaflag = 0;
  int hakuflag = 0;
  int hatuflag = 0;
  int tyunflag = 0;

  oyaflag = random2(100);

  if (oyaflag <= 25) {
    oyaflag = 1;
  } else if (oyaflag <= 50) {
    oyaflag = 2;
  } else {
    oyaflag = 3;
  }

  switch (naki) {
  // 面前
  case 1:
    kakuritu = random2(1000);
    // 立直,ダブル立直,立直なしの選択

    if (kakuritu <= 10) {
      yakflag = 2;
    } else if (kakuritu <= 410) {
      yakflag = 1;
    } else {
      yakflag = 3;
    }
    std::cout << "立直フラグ" << yakflag << std::endl;

    switch (yakflag) {
    // 立直
    case 1:
      yk[1] = reach;
      yak = yakadd(yak, 1);
      reachflag = 1;

      yakflag = 0;
      kakuritu = random2(100);
      // 一発の有無

      if (kakuritu <= 10) {
        yakflag = 1;
      } else {
        yakflag = 2;
      }
      //  std::cout<<"一発フラグ"<<yakflag<<std::endl;

      switch (yakflag) {
      // 一発有
      case 1:
        yk[2] = ippatu;
        yak = yakadd(yak, 1);

      // 一発無
      case 2:
        yak = menzen(yk, yak, oyaflag, reachflag);

        break;
      }
      break;

    // ダブル立直
    case 2:
      yk[1] = doublereach;
      yak = yakadd(yak, 2);
      reachflag = 2;
      
      yakflag = 0;
      kakuritu = random2(100);
        // 一発の有無

      if (kakuritu <= 10) {
        yakflag = 1;
      } else {
        yakflag = 2;
      } 

      switch (yakflag) {
      //  一発有
      case 1:
        yk[2] = ippatu;
        yak = yakadd(yak, 1);
      //  一発無し
      case 2:
        yak = menzen(yk, yak, oyaflag, reachflag);
      break;
      }
      break;

    //  立直なし
    case 3:
      reachflag = 3;
      yak = menzen(yk, yak, oyaflag, reach);
      break;
    }
    break;

    // 鳴きあり

  case 2:
    yak=furo(yk,yak,oyaflag);
  break;
  }

  return yak;
}

int yakmanchose(int naki){
  int x;
  
  return x;
}

//メインプログラム
int main() {
  int flag;
  int nakiflag;
  int yak = 0;
  int kakuritu;
  int outyak;

  kakuritu = random2(1000);

  if (kakuritu < 4) {
    flag = 1;
  } else {
    flag = 2;
  }
  kakuritu = 0;
  kakuritu = random2(1000);
  std::cout << "役満フラグ" << flag << std::endl;

  if (kakuritu <= 701) {
    nakiflag = 1;
  } else {
    nakiflag = 2;
  }
  std::cout << "鳴きフラグ" << nakiflag << std::endl;

  switch (flag) {
  case 1:
    outyak = yakmanchose(nakiflag);
    break;

  case 2:
    outyak = yakchose(nakiflag);
    break;
  }
}