#include <QDebug>

#include "TestDialog.h"
#include "ui_TestDialog.h"

TestDialog::TestDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TestDialog)
{
	ui->setupUi(this);

	/*
	 * SIGNALとSLOTの接続
	 * (参考: http://blog.qt.digia.com/jp/2010/07/20/create-signals-and-slots/)
	 */
	/// lineEditにて、
	///                  ENTERが押されたSIGNALが発行されたら
	///                                                    variableChange()
	///                                                    を呼び出すように
	///                                                    SLOT接続します。
	connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(variableChange()));

	///                  sig_changed()のSIGNALが発生したら
	///                                          logoViewChange()
	///                                          を呼び出すようにSLOT接続します。
	connect(this,SIGNAL(sig_changed()),this,SLOT(logoViewChange()));
}

TestDialog::~TestDialog()
{
	delete ui;
}

/*
 * ダイヤログのlineEditでEnterを押された時の処理
 */
void TestDialog::variableChange()
{
	/*
	 * 直接SLOT()でlogoViewChange()を繋いじゃった方が早いけど
	 * 変数の値を確認し表示を更新する事がしたいらしいので
	 * SIGNALを発生させるサンプルとして、ここでSIGNALを発行させる。
	 * emit するのがポイントね！
	 */
	emit sig_changed();	/// signalを発行
}

/*
 * sig_changed()のSIGNALが発行されたあとのSLOT処理
 * ここで、ダイヤログの画像の表示・非表示を行います。
 */
void TestDialog::logoViewChange()
{
	bool bShow;

	///! lineEditの文字列をDebugの為に、出力しておくね。
	qDebug() << ui->lineEdit->text();

	if( ui->Label_Logo->isVisible() ) {
		bShow = false;	/// LOGOが表示されていたら、表示しない。
	} else {
		bShow = true;	/// LOGOが表示されていなかったら、表示する。
	}

	/// Qt Logoの表示
	ui->Label_Logo->setVisible(bShow);
}
