#pragma once

#include <QRegularExpression>
#include <QSyntaxHighlighter>

class EosSyntaxHighlighter : public QSyntaxHighlighter {
	Q_OBJECT

public:
	EosSyntaxHighlighter(QTextDocument *parent = nullptr);

protected:
	void highlightBlock(const QString &text) override;

private:
	struct HighlightingRule {
		QRegularExpression pattern;
		QTextCharFormat format;
	};
	QList<HighlightingRule> highlightingRules;

	QTextCharFormat modeFormat;
	QTextCharFormat errorFormat;
};
