/* GIO - GLib Input, Output and Streaming Library
 * 
 * Copyright (C) 2006-2007 Red Hat, Inc.
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
 * Author: Alexander Larsson <alexl@redhat.com>
 */

#ifndef __G_DATA_OUTPUT_STREAM_H__
#define __G_DATA_OUTPUT_STREAM_H__

#include <glib-object.h>
#include <gio/gfilteroutputstream.h>
#include <gio/gdatainputstream.h>

G_BEGIN_DECLS

#define G_TYPE_DATA_OUTPUT_STREAM         (g_data_output_stream_get_type ())
#define G_DATA_OUTPUT_STREAM(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), G_TYPE_DATA_OUTPUT_STREAM, GDataOutputStream))
#define G_DATA_OUTPUT_STREAM_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), G_TYPE_DATA_OUTPUT_STREAM, GDataOutputStreamClass))
#define G_IS_DATA_OUTPUT_STREAM(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), G_TYPE_DATA_OUTPUT_STREAM))
#define G_IS_DATA_OUTPUT_STREAM_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), G_TYPE_DATA_OUTPUT_STREAM))
#define G_DATA_OUTPUT_STREAM_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), G_TYPE_DATA_OUTPUT_STREAM, GDataOutputStreamClass))

typedef struct _GDataOutputStream         GDataOutputStream;
typedef struct _GDataOutputStreamClass    GDataOutputStreamClass;
typedef struct _GDataOutputStreamPrivate  GDataOutputStreamPrivate;

struct _GDataOutputStream
{
  GFilterOutputStream parent;

  /*< private >*/
  GDataOutputStreamPrivate *priv;
};

struct _GDataOutputStreamClass
{
 GFilterOutputStreamClass parent_class;

  /* Padding for future expansion */
  void (*_g_reserved1) (void);
  void (*_g_reserved2) (void);
  void (*_g_reserved3) (void);
  void (*_g_reserved4) (void);
  void (*_g_reserved5) (void);
};


GType          g_data_output_stream_get_type   (void) G_GNUC_CONST;
GDataOutputStream*  g_data_output_stream_new        (GOutputStream *base_stream);

void                 g_data_output_stream_set_byte_order (GDataOutputStream     *data_stream,
							  GDataStreamByteOrder   order);
GDataStreamByteOrder g_data_output_stream_get_byte_order (GDataOutputStream     *stream);
void                 g_data_output_stream_set_expand_buffer (GDataOutputStream     *data_stream,
							     gboolean               expand_buffer);

gboolean             g_data_output_stream_put_byte       (GDataOutputStream     *data_stream,
							  guchar                 data,
							  GCancellable          *cancellable,
							  GError               **error);
gboolean             g_data_output_stream_put_int16      (GDataOutputStream     *stream,
							  gint16                 data,
							  GCancellable          *cancellable,
							  GError               **error);
gboolean             g_data_output_stream_put_uint16     (GDataOutputStream     *stream,
							  guint16                data,
							  GCancellable          *cancellable,
							  GError               **error);
gboolean             g_data_output_stream_put_int32      (GDataOutputStream     *stream,
							  gint32                 data,
							  GCancellable          *cancellable,
							  GError               **error);
gboolean             g_data_output_stream_put_uint32     (GDataOutputStream     *stream,
							  guint32                data,
							  GCancellable          *cancellable,
							  GError               **error);
gboolean             g_data_output_stream_put_int64      (GDataOutputStream     *stream,
							  gint64                 data,
							  GCancellable          *cancellable,
							  GError               **error);
gboolean             g_data_output_stream_put_uint64     (GDataOutputStream     *stream,
							  guint64                data,
							  GCancellable          *cancellable,
							  GError               **error);
gboolean             g_data_output_stream_put_string     (GDataOutputStream     *stream,
							  const char            *str,
							  GCancellable          *cancellable,
							  GError               **error);

G_END_DECLS

#endif /* __G_DATA_OUTPUT_STREAM_H__ */