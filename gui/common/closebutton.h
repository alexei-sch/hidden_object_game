#pragma once

namespace Gui
{
class CloseButton : public QWidget
{
	Q_OBJECT

public:
	CloseButton(QWidget* parent);

public:
	Q_SIGNAL void clicked();

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void paintEvent(QPaintEvent*);

private:
	const QImage m_image;
};

}