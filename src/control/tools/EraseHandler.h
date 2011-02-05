/*
 * Xournal Extended
 *
 * Handles the erase of stroken, in special split into different parts etc.
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef ERASEHANDLER_H_
#define ERASEHANDLER_H_

#include "../../model/Page.h"
#include "../../model/Stroke.h"
#include "../ToolHandler.h"
#include "../../gui/Redrawable.h"
#include "../../undo/EraseUndoAction.h"
#include "../../undo/DeleteUndoAction.h"
#include "../../undo/UndoRedoHandler.h"

class DeleteUndoAction;
class EraseUndoAction;

class EraseHandler {
public:
	EraseHandler(UndoRedoHandler * undo, XojPage * page, ToolHandler * handler, Redrawable * view);
	virtual ~EraseHandler();

public:
	void erase(double x, double y);
	void cleanup();

private:
	void eraseStroke(Layer * l, Stroke * s, double x, double y);

private:
	XojPage * page;
	ToolHandler * handler;
	Redrawable * view;
	UndoRedoHandler * undo;

	DeleteUndoAction * eraseDeleteUndoAction;
	EraseUndoAction * eraseUndoAction;

	double halfEraserSize;
};

#endif /* ERASEHANDLER_H_ */