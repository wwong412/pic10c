#include "pictures.h"

Pictures::Pictures()
{
    load();
}

void Pictures::load(){
        QString heart("/Users/Will/Desktop/pic10c/heart.png");
        QString coin("/Users/Will/Desktop/pic10c/coin.png");
        heart_pic = new QPixmap(heart);
        coin_pic = new QPixmap(coin);

        QString vertical_s("/Users/Will/Desktop/pic10c/vertical.png");
        QString across_s("/Users/Will/Desktop/pic10c/across.png");
        QString right_down("/Users/Will/Desktop/pic10c/rightdown3.png");
        QString left_up("/Users/Will/Desktop/pic10c/leftup4.png");
        QString up_right("/Users/Will/Desktop/pic10c/upright5.png");
        QString down_right("/Users/Will/Desktop/pic10c/downright6.png");
        vertical = new QPixmap(vertical_s);
        across = new QPixmap(across_s);
        rd3 = new QPixmap(right_down);
        lu4 = new QPixmap(left_up);
        ur5 = new QPixmap(up_right);
        dr6 = new QPixmap(down_right);

        QString tree1S("/Users/Will/Desktop/pic10c/tree1.png");

        tree1 = new QPixmap(tree1S);

        QString s_pic("/Users/Will/Desktop/pic10c/SQUIRREL1.png");
        QString s_pic2("/Users/Will/Desktop/pic10c/SQUIRREL2.png");
        QString s_pic3("/Users/Will/Desktop/pic10c/SQUIRREL3.png");

        QString p_pic("/Users/Will/Desktop/pic10c/PORCUPINE1.png");
        QString p2_pic("/Users/Will/Desktop/pic10c/PORCUPINE2.png");
        QString p3_pic("/Users/Will/Desktop/pic10c/PORCUPINE3.png");

        QString f_pic("/Users/Will/Desktop/pic10c/FROGGY1.png");
        QString f_pic2("/Users/Will/Desktop/pic10c/FROGGY2.png");
        QString f_pic3("/Users/Will/Desktop/pic10c/FROGGY3.png");
        QString f_pic4("/Users/Will/Desktop/pic10c/FROGGY4.png");

        QString spid_pic("/Users/Will/Desktop/pic10c/SPIDER1.png");
        QString spid_pic2("/Users/Will/Desktop/pic10c/SPIDER2.png");
        QString spid_pic3("/Users/Will/Desktop/pic10c/SPIDER3.png");


        squirrel = new QPixmap(s_pic);
        squirrel2 = new QPixmap(s_pic2);
        squirrel3 = new QPixmap(s_pic3);
        porcupine = new QPixmap(p_pic);
        porcupine2 = new QPixmap(p2_pic);
        porcupine3 = new QPixmap(p3_pic);
        spider = new QPixmap(spid_pic);
        spider2 = new QPixmap(spid_pic2);
        spider3 = new QPixmap(spid_pic3);
        frog = new QPixmap(f_pic);
        frog2 = new QPixmap(f_pic2);
        frog3 = new QPixmap(f_pic3);
        frog4 = new QPixmap(f_pic4);

        QString picks("/Users/Will/Desktop/pic10c/squirrelPick.png");
        QString pickp("/Users/Will/Desktop/pic10c/porcupinePick.png");
        QString pickspid("/Users/Will/Desktop/pic10c/spiderPick.png");
        QString pickf("/Users/Will/Desktop/pic10c/frogPick.png");
        QString white("/Users/Will/Desktop/pic10c/highlight.png");
        sPick = new QPixmap(picks);
        pPick = new QPixmap(pickp);
        spidPick = new QPixmap(pickspid);
        fPick = new QPixmap(pickf);
        shine = new QPixmap(white);
/*
        QString constrMan("/Users/Will/Desktop/pic10c/newman.png");
        QString constrMan1("/Users/Will/Desktop/pic10c/newman2.png");
        QString constrMan2("/Users/Will/Desktop/pic10c/newman3.png");
        QString constrMan3("/Users/Will/Desktop/pic10c/newman3.png");
        man = new QPixmap(constrMan);
        man2 = new QPixmap(constrMan1);
        man3 = new QPixmap(constrMan2);
        man4 = new QPixmap(constrMan3);
*/
        QString constrMan("/Users/Will/Desktop/pic10c/MANBALD1.png");
        QString constrMan1("/Users/Will/Desktop/pic10c/MANBALD2.png");
        QString constrMan2("/Users/Will/Desktop/pic10c/MANBALD3.png");
        QString constrMan3("/Users/Will/Desktop/pic10c/MANBALD4.png");
        man = new QPixmap(constrMan);
        man2 = new QPixmap(constrMan1);
        man3 = new QPixmap(constrMan2);
        man4 = new QPixmap(constrMan3);
        QString hconstrMan("/Users/Will/Desktop/pic10c/MAN1.png");
        QString hconstrMan1("/Users/Will/Desktop/pic10c/MAN2.png");
        QString hconstrMan2("/Users/Will/Desktop/pic10c/MAN3.png");
        QString hconstrMan3("/Users/Will/Desktop/pic10c/MAN4.png");
        hatman = new QPixmap(hconstrMan);
        hatman2 = new QPixmap(hconstrMan1);
        hatman3 = new QPixmap(hconstrMan2);
        hatman4 = new QPixmap(hconstrMan3);

        QString bulldozer("/Users/Will/Desktop/pic10c/tractor1.png");
        QString bulldozer1("/Users/Will/Desktop/pic10c/tractor2.png");
        QString bulldozer2("/Users/Will/Desktop/pic10c/tractor3.png");
        dozer = new QPixmap(bulldozer);
        dozer2 = new QPixmap(bulldozer1);
        dozer3 = new QPixmap(bulldozer2);

        QString selltower("/Users/Will/Desktop/pic10c/money.png");
        QString uptower("/Users/Will/Desktop/pic10c/upgrade.png");
        QString can("/Users/Will/Desktop/pic10c/cancel.png");
        cancel = new QPixmap(can);
        sell = new QPixmap(selltower);
        upgrade = new QPixmap(uptower);

        QString ac("/Users/Will/Desktop/pic10c/acorn.png");
        acorn = new QPixmap(ac);
        QString w("/Users/Will/Desktop/pic10c/web.png");
        web = new QPixmap(w);

        QString starter("/Users/Will/Desktop/pic10c/start.png");
        start = new QPixmap(starter);

        QString circle("/Users/Will/Desktop/pic10c/range.png");
        range = new QPixmap(circle);

        QString pS("/Users/Will/Desktop/pic10c/pause.png");

        pause = new QPixmap(pS);

        QString mtree("/Users/Will/Desktop/pic10c/mothertree.png");
        mTree = new QPixmap(mtree);

        QString jack1("/Users/Will/Desktop/pic10c/jackhammer1.png");
        QString jack2("/Users/Will/Desktop/pic10c/jackhammer2.png");
        jackman1 = new QPixmap(jack1);
        jackman2 = new QPixmap(jack2);

        QString sp1("/Users/Will/Desktop/pic10c/speed1.png");
        QString sp2("/Users/Will/Desktop/pic10c/speed2.png");
        QString sp3("/Users/Will/Desktop/pic10c/speed3.png");
        speed1 = new QPixmap(sp1);
        speed2 = new QPixmap(sp2);
        speed3 = new QPixmap(sp3);

        QString stumpy("/Users/Will/Desktop/pic10c/stump.png");
        stump = new QPixmap(stumpy);

        QString res("/Users/Will/Desktop/pic10c/resumebutton.png");
        resumeButton = new QPixmap(res);
        QString quit("/Users/Will/Desktop/pic10c/quitbutton.png");
        quitButton = new QPixmap(quit);
        QString restart("/Users/Will/Desktop/pic10c/restartbutton.png");
        restartButton = new QPixmap(restart);

}
