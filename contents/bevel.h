/* ------------------------------------------------------------------------- */
/*
 *  contents/bevel.h
 *
 *  Copyright (c) 2009, Four and More, Inc. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    - Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    - Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    - No names of its contributors may be used to endorse or promote
 *      products derived from this software without specific prior written
 *      permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 *  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  Last-modified: Fri 05 Jun 2009 00:09:00 JST
 */
/* ------------------------------------------------------------------------- */
#ifndef FAML_PDF_CONTENTS_BEVEL_H
#define FAML_PDF_CONTENTS_BEVEL_H

#ifndef FAML_PDF_CONTENTS_SHAPE_H
#include "shape.h"
#endif // FAML_PDF_CONTENTS_SHAPE_H

#include "../unit.h"
#include "clx/format.h"
#include "clx/literal.h"

namespace faml {
	namespace pdf {
		namespace contents {
			/* ------------------------------------------------------------- */
			//  basic_bevel
			/* ------------------------------------------------------------- */
			template <
				class CharT,
				class Traits = std::char_traits<CharT>
			>
			class basic_bevel : public basic_shape<CharT, Traits> {
			public:
				typedef basic_shape<CharT, Traits> super;
				typedef typename super::size_type size_type;
				typedef typename super::ostream_type ostream_type;
				
				explicit basic_bevel(const coordinate& o, double w, double h, bool entag = true) :
					super(o, w, h), entag_(entag), adjust_(0.125) {}
				
				virtual ~basic_bevel() throw() {}
				
				virtual size_type has_adjust() const { return 1; }
				virtual double adjust(size_type pos = 0) const { return adjust_; }
				virtual void adjust(double value, size_type pos = 0) { adjust_ = value; }
				
				/* --------------------------------------------------------- */
				//  main operation.
				/* --------------------------------------------------------- */
				bool operator()(ostream_type& out) {
					// No need to draw and/or fill the shape.
					if (!this->is_fill() && !this->is_stroke()) return true;
					
					if (entag_) out << LITERAL("q") << std::endl;
					
					this->setorigin(out);
					this->setborder(out);
					this->setbackground(out);
					
					double ox = -this->width() / 2.0;
					double oy = -this->height() / 2.0;
					double delta = (this->width() < this->height()) ? this->width() * adjust_ : this->height() * adjust_;
					double x = this->width() - delta;
					double y = this->height() - delta;
					
					// Phase 1
					out << fmt(LITERAL("%f %f m")) % (ox + delta) % (oy + delta) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox + x) % (oy + delta) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox + x) % (oy + y) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox + delta) % (oy + y) << std::endl;
					this->draw(out, true);
					
					// Phase 2
					out << fmt(LITERAL("%f %f m")) % (ox + delta) % (oy + y) << std::endl;
					out << fmt(LITERAL("%f %f l")) % ox % (oy + this->height()) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox + this->width()) % (oy + this->height()) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox + x) % (oy + y) << std::endl;
					this->draw(out, true);
					
					double red = this->background().red() * this->shadow().red();
					double green = this->background().green() * this->shadow().green();
					double blue = this->background().blue() * this->shadow().blue();
					
					// Phase 3
					out << fmt(LITERAL("%f %f %f rg")) % red % green % blue << std::endl;
					out << fmt(LITERAL("%f %f m")) % (ox + x) % (oy + y) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox + this->width()) % (oy + this->height()) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox + this->width()) % oy << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox + x) % (oy + delta) << std::endl;
					this->draw(out, true);
					
					red = this->background().red() * this->highlight().red();
					green = this->background().green() * this->highlight().green();
					blue = this->background().blue() * this->highlight().blue();
					
					// Phase 3
					out << fmt(LITERAL("%f %f %f rg")) % red % green % blue << std::endl;
					out << fmt(LITERAL("%f %f m")) % (ox + x) % (oy + delta) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox + this->width()) % oy << std::endl;
					out << fmt(LITERAL("%f %f l")) % ox % oy << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox + delta) % (oy + delta) << std::endl;
					this->draw(out, true);
					
					red = this->background().red() / this->highlight().red();
					green = this->background().green() / this->highlight().green();
					blue = this->background().blue() / this->highlight().blue();
					
					// Phase 4
					out << fmt(LITERAL("%f %f %f rg")) % red % green % blue << std::endl;
					out << fmt(LITERAL("%f %f m")) % (ox + delta) % (oy + delta) << std::endl;
					out << fmt(LITERAL("%f %f l")) % ox % oy << std::endl;
					out << fmt(LITERAL("%f %f l")) % ox % (oy + this->height()) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox + delta) % (oy + y) << std::endl;
					this->draw(out, true);
					
					if (entag_) out << LITERAL("Q") << std::endl;
					
					return true;
				}
				
			private:
				typedef clx::basic_format<CharT, Traits> fmt;
				
				bool entag_;
				double adjust_;
			};
		}
	}
}

#endif // FAML_PDF_CONTENTS_BEVEL_H
