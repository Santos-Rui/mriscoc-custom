/**
 * DWIN G-code File header utility
 * Author: Miguel A. Risco-Castillo
 * version: 1.1.3
 * Date: 2023/03/05
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * For commercial applications additional licenses can be requested
 */

#pragma once

typedef struct {
  char name[13];      //8.3
  bool isConfig;
  uint32_t thumbstart;
  uint16_t thumbsize;
  uint8_t thumbheight;
  uint8_t thumbwidth;
  uint8_t *thumbdata;
  float time;
  float filament;
  float layer;
  float minx;
  float maxx;
  float miny;
  float maxy;
  float minz;
  float maxz;
  float width() { return maxx - minx; };
  float length() { return maxy - miny; };
  float height() { return maxz - minz; };
  void setname(const char * const fn);
  void clear();
} fileprop_t;
extern fileprop_t fileprop;

void getFileHeader();
