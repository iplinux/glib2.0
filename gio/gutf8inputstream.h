/* GIO - GLib Input, Output and Streaming Library
 *
 * Copyright (C) 2009 Paolo Borelli
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Author: Paolo Borelli <pborelli@gnome.org>
 */

#if !defined (__GIO_GIO_H_INSIDE__) && !defined (GIO_COMPILATION)
#error "Only <gio/gio.h> can be included directly."
#endif

#ifndef __G_UTF8_INPUT_STREAM_H__
#define __G_UTF8_INPUT_STREAM_H__

#include <gio/ginputstream.h>
#include <gio/gfilterinputstream.h>

G_BEGIN_DECLS

#define G_TYPE_UTF8_INPUT_STREAM         (g_utf8_input_stream_get_type ())
#define G_UTF8_INPUT_STREAM(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), G_TYPE_UTF8_INPUT_STREAM, GUtf8InputStream))
#define G_UTF8_INPUT_STREAM_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), G_TYPE_UTF8_INPUT_STREAM, GUtf8InputStreamClass))
#define G_IS_UTF8_INPUT_STREAM(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), G_TYPE_UTF8_INPUT_STREAM))
#define G_IS_UTF8_INPUT_STREAM_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), G_TYPE_UTF8_INPUT_STREAM))
#define G_UTF8_INPUT_STREAM_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), G_TYPE_UTF8_INPUT_STREAM, GUtf8InputStreamClass))

/**
 * GUtf8InputStream:
 * @parent_instance: a #GFilterInputStream.
 *
 * An implementation of #GFilterInputStream that performs UTF8 validation.
 *
 * Since: 2.24
 **/
typedef struct _GUtf8InputStreamClass    GUtf8InputStreamClass;
typedef struct _GUtf8InputStreamPrivate  GUtf8InputStreamPrivate;

struct _GUtf8InputStream
{
  GFilterInputStream parent_instance;

  /*< private >*/
  GUtf8InputStreamPrivate *priv;
};

struct _GUtf8InputStreamClass
{
  GFilterInputStreamClass parent_class;

  /*< private >*/
  /* Padding for future expansion */
  void (*_g_reserved1) (void);
  void (*_g_reserved2) (void);
  void (*_g_reserved3) (void);
  void (*_g_reserved4) (void);
  void (*_g_reserved5) (void);
};

GType             g_utf8_input_stream_get_type      (void) G_GNUC_CONST;

GInputStream     *g_utf8_input_stream_new           (GInputStream *base_stream);

G_END_DECLS

#endif /* __G_UTF8_INPUT_STREAM_H__ */
