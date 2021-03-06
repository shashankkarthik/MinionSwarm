/**
 * \file Item.h
 *
 * \author Hector
 *
 * Base class for items
 *
 * Controls how the items work
 */

#pragma once
#include <memory>
#include <string>
#include <vector>
#include "GameVisitor.h"
#include "Vector.h"


class CGame; // forward reference 


/**
* Base class for the Items in the game (Minion, villain, and Gru).
*/
class CItem
{
protected:
	/**
	* Override function
	* \param game, filename
	*/
	CItem::CItem(CGame *game, const std::wstring &filename);

public:
	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem &) = delete;

	virtual ~CItem();

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	void SetLocation(double x, double y);

	///Draw Image
	virtual void CItem::Draw(Gdiplus::Graphics *graphics);
	virtual void CItem::Kill() {};
	virtual int CItem::GetLevel() { return 0; };

	bool HitTest(int x, int y);
	virtual bool IsAlive() { return true; }
	virtual bool HitTestGru(int x, int y) { return false; }

	/** The X location of the item
	* \returns X location in pixels */
	const double GetX() const { return location.X(); }

	/** The Y location of the item
	* \returns Y location in pixels */
	const double GetY() const { return location.Y(); }

	const CVector GetLocation() { return location; }

	virtual void Accept(CGameVisitor *visitor) = 0;

	//If needed
	CGame *GetGameTiles() { return mGameTiles; }
	void SetBorders(float x, float y);

	virtual void Move(double elapsed) {};

	virtual void Flock(CVector cohesionCenter, int numberMinions, CVector alignemnt, CVector mGruLocation, bool mGameOver, CVector Separation) {};

	virtual CVector Alignment(std::vector<CMinion *> minionVector) { CVector basic; return basic; };

	virtual CVector Separation(std::vector<CMinion *> minionVector) { CVector basic; return basic; };

	///Get points for the minion
	virtual int GetPoints() { return 0; }

	virtual void AddPoints(int points) {};

private:

	/// The game this item is contained in
	CGame  *mGameTiles;

	/// The image of this item
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;
	
	/// Item location in the game
	CVector location;

	/// Left border location
	float mXLeftBorder = 0;

	/// Top border location
	float mYTopBorder = 0;

	/// Right border location
	float mXRightBorder = 0;

	/// Bottom border location
	float mYBottomBorder = 0;

};

