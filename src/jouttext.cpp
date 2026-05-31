/*
 * JOutBin.cpp
 *
 * Copyright (C) 2002-2011 Joris Heirbaut
 *
 * This file is part of JojoDiff.
 *
 * JojoDiff is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef __WATCOMC__
#include <io.h>
#endif
#include "JOutText.h"
#include <exception>
#include <sstream>
#include <istream>

namespace JojoDiff {

JOutText::JOutText(FILE *apFilOut, std::string &header) : mpFilOut(apFilOut), msHdr(header), miOprCur(ESC), mzEqlCnt(0), mbOutEsc(false), mbStreamOn(false) {
}

JOutText::JOutText(FILE *apFilOut) : mpFilOut(apFilOut), msHdr(""), miOprCur(ESC), mzEqlCnt(0), mbOutEsc(false), mbStreamOn(false) {
}

JOutText::~JOutText() {
}

void JOutText::ufPutLen ( off_t azLen  )
{ 
#ifdef JDIFF_LARGEFILE
  throw new exception("Large files not supported... yet");
#endif
  fprintf(mpFilOut, " %08lx", azLen);
  gzOutBytCtl+=8;  
} /* ufPutLen */

/* ---------------------------------------------------------------
 * ufPutOpr outputs a new opcode 
 * ---------------------------------------------------------------*/
void JOutText::ufPutOpr ( int aiOpr )
{ 
  if(mbStreamOn) fprintf(mpFilOut, "\n");
  else if(msHdr.size()) {
    fprintf(mpFilOut, "#%s\n", msHdr.c_str());
  }
  const char * cmd;
  switch (aiOpr) {
    case ESC : 
      cmd = "ESC";
      break;

    case MOD :
      cmd = "MOD";
      break;

    case INS :
      cmd = "INS";
      break;

    case DEL :
      cmd = "DEL";
      break;

    case BKT :
      cmd = "BKT";
      break;

    case EQL :
      cmd = "EQL";
      break;

    default:
      cmd = "DFL";
  }
  fprintf(mpFilOut, "%s", cmd);
  gzOutBytCtl++;  
}

/* ---------------------------------------------------------------
 * ufPutByt outputs a byte as text
 * ---------------------------------------------------------------*/
void JOutText::ufPutByt ( int aiByt )
{
  fprintf(mpFilOut, " %02x", aiByt);
  gzOutBytDta++;
}

/* ---------------------------------------------------------------
 * ufOutBytBin: simple text output that matches binary
 * ---------------------------------------------------------------*/
bool JOutText::put (
  int   aiOpr,
  off_t azLen,
  int   aiOrg,
  int   aiNew,
  off_t azPosOrg,
  off_t azPosNew
)
{ /* Output a pending EQL operand (if more than 4 equal bytes) */
  if (aiOpr != EQL && mzEqlCnt > 0) {
    if (mzEqlCnt > 4 || (miOprCur != MOD && aiOpr != MOD)) {
      // more than 4 equal bytes => output as EQL
      miOprCur = EQL;
      ufPutOpr(EQL) ;
      mbStreamOn = true;
      ufPutLen(mzEqlCnt);

      gzOutBytEql+=mzEqlCnt;
    } else {
      // less than 4 equal bytes => output as MOD
      if (miOprCur != MOD) {
        miOprCur = MOD ;
        ufPutOpr(MOD) ;
        mbStreamOn = true;
      }
      for (int liCnt=0; liCnt < mzEqlCnt; liCnt++)
        ufPutByt(miEqlBuf[liCnt]) ;
    }
    mzEqlCnt=0;
  }

  /* Handle current operand */
  switch (aiOpr) {
    case ESC : /* before closing the output */
      ufPutOpr(ESC);
      mbStreamOn = false;
      miOprCur = ESC ;
      break;

    case MOD :
    case INS :
      if (miOprCur != aiOpr) {
        miOprCur = aiOpr ;
        ufPutOpr(aiOpr) ;
      }
      mbStreamOn = true;
      ufPutByt(aiNew) ;
      break;

    case DEL :
      ufPutOpr(DEL) ;
      mbStreamOn = true;
      ufPutLen(azLen);

      miOprCur=DEL;
      gzOutBytDel+=azLen;
      break;

    case BKT :
      ufPutOpr(BKT) ;
      mbStreamOn = true;
      ufPutLen(azLen);

      miOprCur=BKT;
      gzOutBytBkt+=azLen;
      break;

    case EQL :
      if (mzEqlCnt < 4) {
          miEqlBuf[mzEqlCnt++] = aiOrg ;
          return (mzEqlCnt >= 4) ;
      } else {
          mzEqlCnt+=azLen ;
          return true ;
      }
      break;
  }

  return false ;
}
}
